h,w = map(int,input().split())
a = []
for i in range(h):
    atemp = list(input())
    a.append(atemp)

#行を削除
i = 0
counter = 0
line = 0
while counter < h:
    k = 0
    check = True
    while k<w and check:
        if a[i][k] == "#":
            check = False
        else:
            k += 1
    if check:
        a.pop(i)
        line += 1
    else:
        i += 1
    counter += 1

#列を削除
i = 0
k = 0
counter = 0
while counter < w:
    i = 0
    check = True
    while i < h-line and check:
        if a[i][k] == "#":
            check = False
        else:
            i += 1
    if check:
        for j in range(len(a)):
            a[j].pop(k)
    else:
        k += 1
    counter += 1

for i in range(len(a)):
    for k in range(len(a[i])):
        if k != len(a[i]) -1:
            print(a[i][k],end = "")
        else:
            print(a[i][k])