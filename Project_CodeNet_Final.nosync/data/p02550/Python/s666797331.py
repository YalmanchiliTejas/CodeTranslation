n, x, m = map(int, input().split())

i = 0
a = x
aa = set()
aal = []
s = 0
while a not in aa:
    aa.add(a)
    aal.append(a)
    s += a
    i += 1
    if i == n:
        print(s)
        exit(0)
    a = (a ** 2) % m
    if a == 0:
        print(s)
        exit(0)
st  = aal.index(a)
cont = aal[st:]
nc = len(cont)
n -= st
ans = sum(aal[:st]) + sum(cont) * (n // nc) + sum(cont[:(n % nc)])
print(ans)