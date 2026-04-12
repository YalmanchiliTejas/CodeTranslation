#!/usr/bin/env python3

# from typing import Optional
# from typing import List
# from typing import Dict
# from typing import Tuple
# from typing import Sequence


def main():
    N = int(input())
    A = list(map(lambda x: int(x), input().split()))

    sum = 0
    mod = 1000000000 + 7

    sumJ = 0
    for j in range(N):
        sumJ += A[j]

    for i in range(N - 1):
        sumJ -= A[i]
        sum += A[i] * sumJ
        sum = sum % mod

    print(sum)


if __name__ == "__main__":
    main()
