N = int(input())
S = list(input().strip())
K = int(input())

K = K - 1

for i in range(N):
    if S[K] != S[i]:
        S[i] = "*"

print(''.join(S))