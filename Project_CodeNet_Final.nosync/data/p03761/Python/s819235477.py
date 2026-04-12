
from sys import stdin

n = int(stdin.readline().rstrip())
s = [stdin.readline().rstrip() for i in range(n)]
d = {}
dl = []
for i in range(26):
    d.update({chr(i + 97): 0})
for i in range(n):
    dl.append(d.copy())
for i in range(n):
    for si in s[i]:
        dl[i][si] += 1
ans = ''
for al in range(26):
    tmp = 10**9+7
    for i in range(n):
        if tmp > dl[i][chr(al + 97)]:
            tmp = dl[i][chr(al + 97)]
    ans += (tmp * chr(al + 97))

print(ans)