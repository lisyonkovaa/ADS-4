// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] > value)
            break;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] > value - arr[i])
                break;
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int mid = 0;
    int count = 0;
    for (int i = 0; i < len; ++i) {
        left = i + 1;
        right = len - 1;
        if (arr[i] > value)
            break;
        while (left <= right) {
            mid = (right + left) / 2;
            if (arr[mid] == (value - arr[i])) {
                count++;
                int midTwo = mid;
                while (true) {
                    mid--;
                    if (arr[mid] == (value - arr[i]) && mid >= left) {
                        count++;
                    } else {
                        break;
                    }
                }
                while (true) {
                    midTwo++;
                    if (arr[midTwo] == (value - arr[i])) {
                        count++;
                    } else {
                        break;
                    }
                }
                break;
            } else if (value - arr[i] > arr[mid]) {
                left = mid + 1;
            } else if (value - arr[i] < arr[mid]) {
                right = mid - 1;
            }
        }
    }
    return count;
}
