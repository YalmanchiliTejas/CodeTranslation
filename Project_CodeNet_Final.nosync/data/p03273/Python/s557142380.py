H, W = map(int, input().strip().split(" "))

row = []
for i in range(H):
    line = input()
    if line.count(".") == W:
        continue
    row.append(line)

row_count = len(row)
ans = [[] for i in range(row_count)]
for i in range(W):
    tmp = []
    for j in range(row_count):
        tmp.append(row[j][i])
    if tmp.count(".") == row_count:
        continue
    else:
        for index, c in enumerate(tmp):
            ans[index].append(c)
for i in ans:
    print("".join(i))
