h, w = map(int, input().split())

lis = []
for _ in range(h):
    tmp = input()
    lis.append(list(tmp))
    
flag = 0
delg = []
for i in range(h):
    for j in range(w):
        if lis[i][j] == "#":
            flag = 1
            break
        else:
            flag = 0
    
    if flag == 0:
        delg.append(i)
        
nlis = []

if delg != False:    
    for k in range(h):
        if k not in delg:
            nlis.append(lis[k])
            
h = h - len(delg)

flg = 0
delr = []

for k in range(w):
    for i in range(h):
        if nlis[i][k] == "#":
            flg = 1
            break
        else:
            flg = 0
    
    if flg == 0:
        delr.append(k)
        
delr = list(reversed(delr))


if delr != False:
    for i in range(h):
        for j in delr:
            nlis[i].pop(j)

for l in nlis:
    print("".join(l))