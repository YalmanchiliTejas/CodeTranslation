N = int(input())
S = list(input())
K = int(input())

S_kth = S[K-1]
for i in range(N):
    if S[i] != S_kth:
        S[i] ='*'
print(*S, sep='')