h, w = map(int, input().split())
a = [[] for i in range(h)]
for i in range(h):
    a_tmp = input()
    for _ in a_tmp:
        a[i].append(_)
# for i in range(h):
#    print(a[i])
yoko = []
for i in range(h):
    judge = True
    for j in range(w):
        if a[i][j] == "#":
            judge = False
            break
    if judge:
        yoko.append(i)
tate = []
for i in range(w):
    judge = True
    for j in range(h):
        if a[j][i] == "#":
            judge = False
            break
    if judge:
        tate.append(i)
# print(tate)
it = 0
iy = 0
an = [[] for i in range(h-len(yoko))]
# print('sol')
for i in range(h):
    sum = 0
    for j in range(w):
        if i not in yoko and j not in tate:
            print(a[i][j], end="")
            sum += 1
    if sum != 0:
        print("")
