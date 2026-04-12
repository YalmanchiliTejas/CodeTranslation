H, W = map(int, input().split())

tmp = []
for i in range(H):
    row = input()
    if '#' in row:
        tmp.append(row)

res = [''] * len(tmp)
for col in zip(*tmp):
    if '#' in col:
        for j in range(len(tmp)):
            res[j] += col[j]

print(*res, sep='\n')
