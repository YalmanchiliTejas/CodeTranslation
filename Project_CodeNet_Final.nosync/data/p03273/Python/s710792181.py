import itertools

h,w = map(int, input().split())

area = []
for i in range(h):
    array = list(input())
    area.append(array)

a = list(itertools.chain.from_iterable(area))

yoko = []
tate = []

for i in range(h):
    cnt = 0
    for j in range(w):
        if area[i][j] == '#':
            cnt += 1
    if cnt == 0:
        yoko.append(i)

for i in range(w):
    b = a[i::w]
    if len(set(b)) == 1 and '.' in set(b):
        tate.append(i)

for i in range(h):
    flg = False
    for j in range(w):
        if j in set(tate):
            continue
        elif i in set(yoko):
            flg = True
            continue
        else:
            print(area[i][j], end='')
    if flg == False:
        print()