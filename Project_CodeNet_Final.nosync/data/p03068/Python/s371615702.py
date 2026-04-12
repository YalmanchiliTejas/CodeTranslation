N = int(input())
S = list(input())
K = int(input())

for i in range(N):
    if S[K-1] != S[i]:
        S[i] = '*'

print(''.join(S))