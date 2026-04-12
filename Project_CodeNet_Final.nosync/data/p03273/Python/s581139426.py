H,W = map(int,input().split())
ma = [input() for i in range(H)]
ol = []
for i in range(len(ma)):
    if '#' in ma[i]:
        ol.append(ma[i])
f = True
deli = []
for i in range(len(ma[0])):
    f = True
    for i2 in range(len(ma)):
        if ma[i2][i] == '#':
           f = False
           break
    if f:
        deli.append(i)

for o in ol:
    s = ""
    for i in range(len(o)):
        if not i in deli:
            s += o[i]
    print(s)
