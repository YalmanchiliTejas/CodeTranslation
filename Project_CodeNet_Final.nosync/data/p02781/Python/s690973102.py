import math

def comb(n, r):
    if r < 0 or r > n:
        return 0

    if r == 1:
        return n
    elif r == 2:
        return n* (n - 1) / 2
    else:
        return n * (n - 1) * (n - 2) / 6

def solve(i, k, smaller):
    if i == N:
        if k == 0:
            return 1
        else:
            return 0

    if k == 0:
        return 1

    if smaller:
        return comb(N - i, k) * math.pow(9, k)
    else:
        if S[i] == "0":
            return solve(i + 1, k, False)
        else:
            zero = solve(i + 1, k, True)
            aida = solve(i + 1, k - 1, True) * (int(S[i]) - 1)
            icchi = solve(i + 1, k - 1, False)
            return int(zero + aida + icchi)

S = input()
K = int(input())
N = len(S)

print(solve(0, K, False))
