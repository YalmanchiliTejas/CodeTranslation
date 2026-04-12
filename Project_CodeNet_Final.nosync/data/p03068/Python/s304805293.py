N = int(input())
S = input()
K = int(input())

rep = S[K-1]
ans = ""

for s in S:
    if s == rep:
        ans += s
    else:
        ans += '*'

print(ans)
