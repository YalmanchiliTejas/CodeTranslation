
h, w = map(int, input().split())
As = [input() for _ in range(h)]

Bs = []
for a in As:
    if "#" in a:
        Bs.append(a)

Cs = list(map(list, zip(*Bs)))
Ds = []
for c in Cs:
    if "#" in c:
        Ds.append(c)

ret = list(map(list, zip(*Ds)))
for x in ret:
    print(*x, sep="")