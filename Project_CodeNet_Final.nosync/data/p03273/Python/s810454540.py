H, W = map(int,input().split())
map = [[str(i) for i in input()] for j in range(H)]
delList1 = []
delList2 = []
for k in range(H):
    if "#" not in map[k]:
        delList1.append(k)

for l in reversed(delList1):
    del map[l]

for m in range(W):
    if "#" not in [n[m] for n in map]:
        delList2.append(m)

for o in reversed(delList2):
    for p in range(len(map)):
        map[p].pop(o)

for q in map:
    print("".join(q))