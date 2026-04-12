from sys import stdin
n = int(stdin.readline())
a = []
for _ in xrange(n):
    s = stdin.readline().strip()
    di = {}
    for i in s:
        di[i] = di.get(i,0) + 1
    a.append(di)       
ans = ''
b = 'abcdefghijklmnopqrstuvwxyz'
for i in b:
    x = 10**5
    for yy in a:
        x = min(x, yy.get(i,0))
    ans += x*i
print ans    