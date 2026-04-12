N = int(input())
S = input()
K = int(input())

c = S[K - 1]
ans = ''
for d in S:
    if d != c:
        ans += '*'
    else:
        ans += c
print(ans)