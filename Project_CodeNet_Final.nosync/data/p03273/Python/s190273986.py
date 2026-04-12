H, W = map(int, input().split())
field = []
for _ in range(H):
    tmp = input()
    if tmp.count('#') == 0:
        continue
    else:
        field.append(tmp)
ans_field = [""] * len(field)
for column in range(W):
    del_flag = True
    for row in range(len(field)):
        if field[row][column] == '#':
            del_flag = False
            break
    if not del_flag:
        for row in range(len(field)):
            ans_field[row] += field[row][column]
for val in ans_field:
    print(val)
