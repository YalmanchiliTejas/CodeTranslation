# coding: utf-8
# Your code here!

N = int(input())
S = [x for x in input()]
K = int(input()) - 1

for i, s in enumerate(S):
    if S[K] != s:
        S[i] = '*'
        
print(''.join(S))