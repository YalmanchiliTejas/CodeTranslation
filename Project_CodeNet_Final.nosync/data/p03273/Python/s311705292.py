h, w = map(int, input().split())
hlist = []
wlist = []
a = [list(input()) for i in range(h)]
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            hlist.append(i)
            wlist.append(j)
for i in set(hlist):
    for j in set(wlist):
        print(a[i][j], end ="")
    print()