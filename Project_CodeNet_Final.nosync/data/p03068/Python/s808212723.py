N = int(input())
S = input()
K = int(input())
p = S[K-1]
ans = ""
for k in range(N):
    if S[k] == p:
        ans += p
    else:
        ans += "*"
print(ans)