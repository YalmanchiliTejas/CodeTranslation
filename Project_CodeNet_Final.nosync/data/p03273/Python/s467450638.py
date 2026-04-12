h, w = map(int, input().split())
field = list(input() for i in range(h))

row = [0] * h
column = [0] * w
for i in range(h):
    for j in range(w):
        if field[i][j] == '#':
            row[i] = 1
            column[j] = 1

for i in range(h):
    if row[i] == 1:
        for j in range(w):
            if column[j] == 1:
                print(field[i][j], end='')
        print()
