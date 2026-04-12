from sys import stdin
inf = 10**10
n = int(stdin.readline().rstrip())
to = [inf]*26
s = 'abcdefghijklmnopqrstuvwxyz'
for i in range(n):
    li = [0]*26
    p = stdin.readline().rstrip()
    for j in range(len(s)):
        li[j] += p.count(s[j])
    for k in range(26):
        to[k] = min(to[k],li[k])
sn = ""
for i in range(26):
    if to[i] > 0:
        sn += s[i]*to[i]
print(sn)