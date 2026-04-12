N = int(input())
S = input()
K = int(input())

s = S[K - 1]

ans = ''

for i in range(N):
    if S[i] == s:
        ans += S[i]
    else:
        ans += '*'

print(ans)
