N = int(input())
S = input()
K = int(input())
a = S[K-1]
ans = ""
for i in range(N):
    if S[i] != a:
        ans += "*"
    else:
        ans += S[i]
print(ans)