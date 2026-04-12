h, w = map(int,input().split())
c = []


for i in range(h):
    tmp = input()
    flag = 0
    for j in range(len(tmp)):
        if tmp[j] == '#':
            flag = 1
            break
    if flag == 0:
        continue
    else:
        c.append(tmp)

tate = []

for i in range(len(c[0])):
    flag = 0
    for j in range(len(c)):
        if c[j][i] == '#':
            flag = 1
            break
    if flag == 0:
        tate.append(i)

for i in range(len(c)):
    c[i] = list(c[i])
    for j in range(len(tate)):
        c[i].pop(tate[j]-j)
    c[i] = ''.join(c[i])
    print(c[i])
