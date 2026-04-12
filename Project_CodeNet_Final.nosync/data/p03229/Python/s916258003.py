import sys
import math  # noqa
import bisect  # noqa
import queue  # noqa
from collections import deque


def input():
    return sys.stdin.readline().rstrip()


def main():
    N = int(input())

    A = []
    for _ in range(N):
        A.append(int(input()))
    A.sort()

    left_idx = 0
    right_idx = N - 1
    left = A[left_idx]
    right = A[right_idx]
    res = abs(right - left)
    left_idx += 1
    right_idx -= 1
    while left_idx <= right_idx:
        al = A[left_idx]
        ar = A[right_idx]
        dl = max(abs(al - left), abs(al - right))
        dr = max(abs(ar - left), abs(ar - right))
        if dl < dr:
            if abs(ar - left) < abs(ar - right):
                res += abs(ar - right)
                right = ar
            else:
                res += abs(ar - left)
                left = ar
            right_idx -= 1
        else:
            if abs(al - left) < abs(al - right):
                res += abs(al - right)
                right = al
            else:
                res += abs(al - left)
                left = al
            left_idx += 1

    print(res)


if __name__ == '__main__':
    main()
