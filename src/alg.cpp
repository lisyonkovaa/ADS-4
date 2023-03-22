int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            ++count;
            while (left < right && arr[left] == arr[left + 1]) {
                ++left;
            }
            while (left < right && arr[right] == arr[right - 1]) {
                --right;
            }
            ++left;
            --right;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int diff = value - arr[i];
        int* found = std::lower_bound(arr + i + 1, arr + len, diff);
        if (found != arr + len && *found == diff) {
            ++count;
            while (found + 1 < arr + len && *(found + 1) == diff) {
                ++found;
                ++count;
            }
        }
    }
    return count;
}
