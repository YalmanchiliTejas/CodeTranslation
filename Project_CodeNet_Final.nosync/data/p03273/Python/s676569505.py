_in = input()
h, w = [int(i) for i in _in.split(' ')]

data = []
for i in range(h):
    _input = input()
    data.append([char for char in _input])

del_row_idx = []
for i, row in enumerate(data):
    tf = [char=='.' for char in row]
    flag = True
    for t in tf:
        flag *= t
    if flag:
        del_row_idx.append(i)

del_col_idx = []
for i in range(w):
    tf = [char=='.' for char in [row[i] for row in data]]
    flag = True
    for t in tf:
        flag *= t
    if flag:
        del_col_idx.append(i)

for idx in del_row_idx[::-1]:
    data.pop(idx)

for idx in del_col_idx[::-1]:
    for row in data:
        row.pop(idx)

for d in data:
    print(''.join(d))
