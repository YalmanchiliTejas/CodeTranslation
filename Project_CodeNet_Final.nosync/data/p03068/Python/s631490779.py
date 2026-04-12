N = int(input())
S = str(input())
K = int(input())

target = S[K-1]
ans = ''
for i in range(N):
    if S[i] == target:
        ans += S[i]
    else:
        ans += '*'

print(ans)
