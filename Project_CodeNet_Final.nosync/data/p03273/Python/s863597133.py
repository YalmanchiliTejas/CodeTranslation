H, W = map(int, input().split())
row_list = []
[row_list.append(input()) for h in range(H)]

col_list = []
for w in range(W):
    col = ''
    for h in range(H):
        col += row_list[h][w]
    col_list.append(col)


romit_index_list = [rindex for rindex, r in enumerate(row_list) if r == '.' * W]
comit_index_list = [cindex for cindex, c in enumerate(col_list) if c == '.' * H]

matrix = ''
for h in range(H):
    if h in romit_index_list:
        pass
    else:
        for w in range(W):
            if w in comit_index_list:
                pass
            else:
                matrix += row_list[h][w]


result = [matrix[n: n + W - len(comit_index_list)]
          for n in range(0, len(matrix), W - len(comit_index_list))]


ans = '\n'.join(result)
print(ans)
