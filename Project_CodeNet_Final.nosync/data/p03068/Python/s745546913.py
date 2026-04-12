N = int(input())
S = str(input())
K = int(input())

oki = S[K-1]
ans = ""
for i in range(N):
    if S[i] == oki:
        ans += S[i]
    else:
        ans += "*"

print(ans)