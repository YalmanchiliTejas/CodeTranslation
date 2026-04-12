
n = int(input())


lst = []
for _ in range(n):
    d = {}
    s = input()
    for i in s:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    lst.append(d)

keys = [list(d.keys()) for d in lst]

a = set(keys[0])
for i in range(1, n):
    a = a & set(keys[i])


ret = {k: 100 for k in a}
for d in lst:
    for k in a:
        ret[k] = min(ret[k], d[k])

s = ""
for k, v in ret.items():
    s += k*v

s = "".join(sorted(s))

print(s)
