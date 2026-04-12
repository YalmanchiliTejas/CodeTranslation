N = int(input())
S = input()
K = int(input())

ch = S[K-1]
ans = ''
for v in S:
    if v == ch:
        ans += v
    else:
        ans += '*'
print(ans)