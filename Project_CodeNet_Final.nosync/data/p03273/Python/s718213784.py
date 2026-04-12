h, w = map(int, input().split())

table = [[] for _ in range(h)]
skiph = []
skipw = []
for i in range(h):
    table[i] = list(input())
    if len(set(table[i])) == 1:
        if table[i][0] == ".":
            skiph.append(i)

for i in range(w):
    if table[0][i] == ".":
        for j in range(h):
            if table[j][i] != ".":
                break
        else:
            skipw.append(i)

for i in range(h):
    if i in skiph:
        continue
    for j in range(w):
        if j in skipw:
            continue
        else:
            print(table[i][j], end="")
    print()
