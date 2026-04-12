n = int(input())
a = 'abcdefghijklmnopqrstuvwxyz'
l = [input() for _ in range(n)]
res = []
for i in a:
    mi = 100
    for j in l:
        mi = min(mi, j.count(i))
    res.append(mi)
ans = ''
for i in range(26):
    ans += a[i]*res[i]
print(ans)