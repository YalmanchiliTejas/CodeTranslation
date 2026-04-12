nl = lambda: list(map(int, input().split()))
sl = lambda: input().split()
n = lambda: int(input())
s = lambda: input()

H, W = nl()

mas = []
for i in range(H):
    row = s()
    if row == '.' * W:
        continue
    mas.append(row)

rmas = ['' for i in range(W)]
for row in mas:
    for i in range(W):
        rmas[i] += row[i]

res = []
for row in rmas:
    if row == '.' * len(mas):
        continue
    res.append(row)

for i in range(len(mas)):
    row = ''
    for j in range(len(res)):
        row += res[j][i]
    print(row)

