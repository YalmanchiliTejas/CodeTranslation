N = int(input())
S = input()
K = int(input()) - 1
s = S[K]
ans = ''

for i in S:
    if i == s:
        ans += i
    else:
        ans += '*'

print(ans)