N = int(input())
S = input()
K = int(input())
ans = ""
for i in range(N):
    if S[K-1] == S[i]:
        ans += S[i]
    else:
        ans += "*"
print(ans)
