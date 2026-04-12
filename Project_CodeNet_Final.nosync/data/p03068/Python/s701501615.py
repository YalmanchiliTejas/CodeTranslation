N = int(input())
S = list(input())
K = int(input())
for n in range(N):
    if S[n] != S[K-1]:
        S[n] = '*'
print(*S,sep='')
