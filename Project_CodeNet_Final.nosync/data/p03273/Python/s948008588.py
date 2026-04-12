H, W = map(int, input().split())
vax = []
hax = []
a = [str(input()) for i in range(H)]
for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            if i not in vax:
                vax.append(i)
            if j not in hax:
                hax.append(j)
vax.sort()
hax.sort()       
for i in vax:
    for j in hax:
        b = a[i][j]
        print(b,end="")
    print("")