# C - Sum of product of pairs
from itertools import accumulate


def main():
    N, *A = map(int, open(0).read().split())
    rev_cumsum = list(accumulate(reversed(A[1:])))[::-1]
    MOD = 10 ** 9 + 7
    res = sum(a * c for a, c in zip(A[:-1], rev_cumsum)) % MOD
    print(res)


if __name__ == "__main__":
    main()
