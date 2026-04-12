H,W = map(int,input().split())
Data1 = []

tbl = str.maketrans({'.':'0','#':'1'})
for _ in range(H):
    s = input().translate(tbl)
    s = list(map(int,list(s)))
    if sum(s) > 0:
        Data1.append(s)

dellist = []
for w in range(W):
    flag = False
    for data in Data1:
        if data[w] == 1:
            flag = True
            break
    if flag == False:
        dellist.append(w)

for i in range(len(dellist)-1,-1,-1):
    for data in Data1:
        data.pop(dellist[i])

for data in Data1:
    for i in range(len(data)):
        if data[i] == 0:
            print('.',end='')
        else:
            print('#',end='')
    print("")