h, w = map(int, input().split())
mas = []

for _ in range(h):
    row = input()
    if '#' in row:
        mas.append(list(row))

ignore_col = []
for i in range(w):
    cnt = 0
    for j in range(len(mas)):
        if mas[j][i] == '#':
            break
        cnt += 1
    if cnt == len(mas):
        ignore_col.append(i)

for i in range(len(mas)):
    tmp = []
    for j in range(w):
        if j in ignore_col:
            continue
        tmp.append(mas[i][j])
    print(''.join(tmp))
