N = int(input())
S = input()
K = int(input())

c = S[K - 1]

ans = ''
for i, s in enumerate(S):
    if s == c:
        ans += s
    else:
        ans += '*'

print(ans)