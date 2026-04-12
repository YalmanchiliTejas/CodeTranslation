h, w = [int(v) for v in input().split()]
a = []
for i in range(h):
    row = input()
    if '#' in row:
        a.append(list(row))

remove_column = []
for j in range(w):
    if len([True for v in a if v[j] == '#']) == 0:
        remove_column.append(j)
remove_column = remove_column[::-1]

for j in remove_column:
    for i in range(len(a)):
        a[i].pop(j)

for line in a:
    print(''.join(line))