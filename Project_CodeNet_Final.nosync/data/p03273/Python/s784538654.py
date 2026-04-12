# from pprint import pprint

# import math
# import collections

# n = int(input())
h, w = map(int, input().split(' '))
# a = list(map(int, input().split(' ')))

a = []
for _h in range(h):
    a.append(list(input()))

mask = [[False] * w for h in range(h)]

# 行の判定
for i, row in enumerate(a):
    if all([True if c == '.' else False for c in a[i]]):
        mask[i] = [True] * w

# 列の判定
x = [True] * w
for row in a:
    for j, col in enumerate(row):
        if col == '.':
            x[j] = x[j] and True
        else:
            x[j] = x[j] and False

for i, row in enumerate(a):
    for j, _x in enumerate(x):
        if _x:
            mask[i][j] = True

for i in range(h):
    if all(mask[i]):
        continue
    p_row = ''.join([a[i][j] for j in range(w) if mask[i][j] is False])
    print(p_row)
