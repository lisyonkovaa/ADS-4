// Copyright 2021 NNTU-CS
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
    for (int i = 0; i < len; i++) {
        int start = i + 1, end = len - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] + arr[i] == value) {
                count++;
                break;
            } else if (arr[mid] + arr[i] < value) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return count;
}
