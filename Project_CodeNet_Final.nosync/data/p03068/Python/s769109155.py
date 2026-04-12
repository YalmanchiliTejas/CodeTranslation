# coding: utf-8
# Your code here!


N = int(input())
S = input()
K = int(input())

char = S[K - 1]
# print(char)

ret = ''

for i in range(len(S)):
    if S[i] != char:
        ret += '*'
    else:
        ret += S[i]

print(ret)
