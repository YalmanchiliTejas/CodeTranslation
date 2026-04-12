import collections

n = int(input())
s = [input() for i in range(n)]
w = ""
if n == 1:
    r = collections.Counter(s[0])
    for k in sorted(r):
        w += k * r[k]
    print(w)
    exit()
a = collections.Counter(s[0])
b = collections.Counter(s[1])
res = a & b
if n <= 2:
    for k in sorted(res):
        w += k * res[k]
    print(w)
else:
    for i in s[2:]:
        res = res & collections.Counter(i)
    if not res:
        print("")
    for k in sorted(res):
        w += k * res[k]
    print(w)