# coding: utf-8
N = int(input())
S = list(input())
K = int(input()) - 1
str = S[K]
print(''.join([i if i == str else '*' for i in S]))