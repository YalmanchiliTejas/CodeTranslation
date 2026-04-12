N = int(input())
S = list(input())
K = int(input())-1

ans = ''
p = S[K]
for i in range(N):
    if p == S[i]:
        ans += S[i]
    else:
        ans += '*'

print(ans)
