N = int(input())
S = input()
K = int(input())
ans = ""

x = S[K-1]
for i in range(len(S)):
    if S[i] != x:
        ans += "*"
    else:
        ans += S[i]

print(ans)
    