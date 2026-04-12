N = int(input())
S = str(input())
K = int(input())

t = S[K - 1]

ans = ''
for i in S:
    if i == t:
        ans += i
    else:
        ans += '*'

print(ans)