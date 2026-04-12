import collections
N = int(input())
K = int(input())

memo = [
    collections.defaultdict(int),
    collections.defaultdict(int),
    collections.defaultdict(int),
    collections.defaultdict(int)
]


def rec(n, k):
    if k == 0:
        return 1
    elif n < 10:
        if k == 1:
            return n
        else:
            return 0
    elif n in memo[k]:
        return memo[k][n]
    digit = len(str(n))
    top = (n // (10**(digit - 1))) * 10**(digit - 1)
    residue = n - top
    hoge = rec(top - 1, k) + rec(residue, k - 1)
    memo[k][n] = hoge
    return hoge


print(rec(N, K))
