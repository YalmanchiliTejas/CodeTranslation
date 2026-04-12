N = int(input())
S = input()
K = int(input())

c = S[K-1]
ans = ''
for s in S:
    if c != s:
        ans += '*'
    else:
        ans += s
print(ans)
