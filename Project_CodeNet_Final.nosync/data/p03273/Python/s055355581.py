
h, w = map(int, input().split())
As = [input() for _ in range(h)]

Bs = [x for x in As if "#" in x]
Cs = list(zip(*Bs))
Ds = [x for x in Cs if "#" in x]
ret = list(zip(*Ds))

for x in ret:
    print(*x, sep="")