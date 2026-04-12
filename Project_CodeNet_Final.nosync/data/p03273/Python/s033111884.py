H,W = list(map(int,input().split()))
HWlist = []
w = []

for i in range(H):
    list = [i for i in input()]
    if list.count("#") > 0:
        HWlist.append(list)
    for j in range(W):
        if list[j] == "#":
            w.append(j)
    
for i in range(len(HWlist[0])-1,-1,-1):
    if i not in w:
        for j in HWlist:
            del j[i]

for i in range(len(HWlist)):
    print("".join(HWlist[i]))