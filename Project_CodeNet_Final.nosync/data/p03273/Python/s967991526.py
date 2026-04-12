h, w = map(int, input().split())
maplist = []
h2 = h
for i in range(h):
    k = [x for x in input()]
    for j in range(len(k)):
        if k[j] == "#":
            maplist.append(k)
            break
        if j == len(k)-1:
            h2 -= 1
deletelist = []
for i in range(w):
    for j in range(h2):
        if maplist[j][i] == "#":
            break
        if j == h2-1:
            deletelist.append(i)
deletelist = reversed(deletelist)
for i in deletelist:
    for j in range(h2):
        maplist[j].pop(i)
for i in range(h2):
    print("".join(maplist[i]))