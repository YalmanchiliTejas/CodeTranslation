N = int(input())
S = input()
K = int(input())

anchor = S[K-1]
ans = ""
for i in range(N):
    if S[i] != anchor:
        ans += '*'
    else:
        ans += anchor

print(ans)