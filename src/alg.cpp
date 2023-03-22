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
    int start = 0, end = len - 1;
    while (start < end) {
        if (arr[start] + arr[end] == value) {
            count++;
            start++;
            end--;
        } else if (arr[start] + arr[end] < value) {
            start++;
        } else {
            end--;
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
