H,W = map(int,input().split())
l = [list(input()) for i in range(H)]
#print(H,W,l)


wlist = []
hlist = []
harray = []
for i in range(H):
    flag = 0
    for j in range(W):
        if l[i][j] == "#":
            flag = 1
    if flag == 1:
        hlist.append(i)
for i in hlist:
    harray.append(l[i])
H = len(harray)

for i in range(W):
    flag = 0
    for j in range(H):
        if harray[j][i] == "#":
            flag = 1
    if flag == 0:
        wlist.append(i)
for i in wlist:
    for j in range(H):
        harray[j][i] = "n"

for i in harray:
    for x in i:
        if x != "n":
            print(x,end="")
    print()