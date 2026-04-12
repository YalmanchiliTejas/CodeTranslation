# coding: utf-8

N, S, K = int(input()), input(), int(input())
char = S[K - 1]
A = ''
for i in range(len(S)):
    if S[i] == char:
        A += S[i]
    else:
        A += '*'
print(A)