h, w = map(int, input().split())

table = []
row = [0 for _ in range(h)]
column = [0 for _ in range(w)]
for j in range(h):
    temp = [] + list(input())
    table.append(temp)
    check = 0
    for i in range(w):
        if temp[i] == '#':
            check = 1
            column[i] = 1
    row[j] = check

for i in range(h):
    if row[i] == 0:
        continue

    temp = [] + table[i]
    for j in range(w):
        if column[j] == 0:
            temp[j] = ''

    print(''.join(temp))
