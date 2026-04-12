h, w = map(int, input().split())

ls = [input() for _ in range(h)]
drops_h = []
drops_w = []

for i in range(h):
    if all([ls[i][j] == '.' for j in range(w)]):
        drops_h.append(i)

for i in range(w):
    if all([ls[j][i] == '.' for j in range(h)]):
        drops_w.append(i)

for i in range(h):
    if i in drops_h:
        continue
    else:
        for j in range(w):
            if j in drops_w:
                continue
            else:
                print(ls[i][j], end='')
        print()