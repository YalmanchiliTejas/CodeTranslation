from sys import stdin
N = int(stdin.readline().rstrip())
S = list(input())
K = int(stdin.readline().rstrip())
for s in S:
    if s != S[K-1]:
        print('*', end="")
    else: print(s, end="")
