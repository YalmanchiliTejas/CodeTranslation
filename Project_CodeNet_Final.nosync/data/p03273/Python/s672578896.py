H,W = [int(x) for x in input().split()]
a = [0]*H
ng_h = []
ng_w = []
for i in range(H):
    a[i] = [1 if x == '#' else 0 for x in input()]

for i in range(H):
    if(sum(a[i]) == 0):
        ng_h.append(i)
for j in range(W):
    sumw = 0
    for i in range(H):
        sumw += a[i][j]
    if(sumw == 0):
        ng_w.append(j)


for i in range(H):
    flag = False
    for j in range(W):
        if((not i in ng_h) and (not j in ng_w)):
            flag = True
            print('#' if a[i][j] == 1 else '.',end = '')
    if(flag):
        print()