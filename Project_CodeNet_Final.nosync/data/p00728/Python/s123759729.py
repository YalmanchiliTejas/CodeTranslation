Ps = []

while True:
    i = int(input())
    if i == 0:
        break
    P = []
    P.append(i)
    for ii in range(i):
        P.append(int(input()))

    Ps.append(P)

for p in Ps:
    p[0] = 0
    p.sort()
    p[1] = 0
    p[-1] = 0
    print(int(sum(p) / (len(p) - 3)))
