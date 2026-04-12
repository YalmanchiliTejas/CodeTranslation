input()
S = input()
K = int(input())
for s in S:
    print('*' if s != S[K-1] else s, end='')