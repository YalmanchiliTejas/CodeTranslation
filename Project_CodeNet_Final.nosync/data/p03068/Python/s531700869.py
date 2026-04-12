N = int(input())
S = str(input())
K = int(input())
ans = ""
tmp = S[K-1]
for i in range(N):
    if S[i] == tmp:
        ans += tmp
    else:
        ans += "*"
print(ans)