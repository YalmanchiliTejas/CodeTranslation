N = int(input())
S = str(input())
K = int(input())
for n in range(N):
    if S[n] != S[K-1]:
        S = S[:n] + '*' + S[n+1:]
print(S)