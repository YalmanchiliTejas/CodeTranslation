N = int(input())
S = list(str(input()))
K = int(input())
for i in range(0, N):
    if S[i] != S[K-1]:
        S[i] = '*'
print(*S, sep='')