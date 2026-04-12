import string

n = int(input())
ls = [input().rstrip() for _ in range(n)]
cs = {c: [] for c in string.ascii_lowercase}
for i in range(n):
    for c in string.ascii_lowercase:
        k = ls[i].count(c)
        cs[c].append(k)
res = ''
for c in string.ascii_lowercase:
    res += c * min(cs[c])
print(res)