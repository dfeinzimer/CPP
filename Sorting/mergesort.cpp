/*
 * mergesort.cpp
 * Implementation of a bitonic mergesort
 */

/* merge(input, size, output, asc)
   Merge the two halves of the array input (which has size elements) into
   output. If asc is true, then the output array should be in ascending order;
   otherwise it should be descending.
*/
void merge(int* input, int size, int* output, bool output_asc) {
    // Your merge implementation goes here
    int mid = size / 2;
    int i = 0, j = mid, k = 0;

    while(i < mid && j < size) {
        // Add the smaller of s1, s2 to output.

        if (output_asc == true) {
            if (input[i] <= input[j]) {
                output[k++] = input[i++];
            }
            else {
                output[k++] = input[j++];
            }
        } else {
            if (input[i] <= input[j]) {
                output[k++] = input[i++];
            }
            else {
                output[k++] = input[j++];
            }
        }

    }

    // Reached the end of one or both, add any remaining elements
    // Only one (or zero) or these loops will ever run, never both.
    while(i < mid)  output[k++] = input[i++];
    while(j < size) output[k++] = input[j++];
    
}

/* mergesort(input, size, output, asc)
   Mergesort the input array (with size elements) into the output array. If
   asc is true, the output array should be sorted ascending, otherwise it should
   be descending.
*/
void mergesort(int *input, int size, int* output, bool output_asc) {
    // Your mergesort implementation goes here
    if (size == 0) {
        return;
    }
    else if (size == 1) {
        output[0] = input[0]; // Copy one
        return;
    }

    int* temp = new int[size]; // Temporary space

    int mid = size / 2;

    mergesort(input,       mid,        temp,       output_asc);    // Sort lower half
    mergesort(input + mid, size - mid, temp + mid, output_asc);    // Sort upper half
    mergesort(input,       size,       temp,       output_asc); // Merge

    // Copy to output
    for (int i = 0; i < size; ++i) {
        output[i] = temp[i];
    }

    delete[] temp;
}

/* mergesort(input, size)
   Sorts size elements in the array pointed to by input, using the MergeSort
   algorithm. Output is returned as a newly allocated array, which the caller
   is responsible for freeing.
*/
int* mergesort(int* input, int size) {
    int* output = new int[size];
    mergesort(input, size, output, true);
    return output;
}