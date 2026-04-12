N = int(input())
S = str(input())
K = int(input())
ans = ""
for i in range(0, N):
    if(S[i] != S[K-1]):
        ans += "*"
    else:
        ans += S[K-1]
print(ans)
