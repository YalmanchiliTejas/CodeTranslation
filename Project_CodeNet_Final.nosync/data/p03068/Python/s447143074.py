n = int(input())
s = str(input())
k = int(input())

_s = s[k-1]
ans = ''
for i in range(n):
    if s[i] == _s:
        ans += _s
    else:
        ans += '*'

print(ans)
