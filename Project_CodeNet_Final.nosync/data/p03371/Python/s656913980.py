# coding: utf-8

A, B, C, X, Y = map(int, input().split(" "))


n = 10 ** 10
min_a = min_b = min_c = 10**10
max_ab = 0
for ab in range(0, 2*max(X, Y) + 2, 2):
    a = max(X - ab//2, 0)
    b = max(Y - ab//2, 0)
    n = min(n, a*A + b*B + ab*C)

print(n)
