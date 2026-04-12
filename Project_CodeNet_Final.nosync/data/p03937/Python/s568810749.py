"""
i-1行目の右端のマスとi行目の左端のマスが隣接しており、
それらの行においてはそれ以外のマスは隣接していないこと。

以上を満たした場合に'Possible'を出力すればよさそう。
"""
H, W = map(int, input().split())
table = [input() for _ in range(H)]
pre_row = [i for i, x in enumerate(table[0]) if x == "#"]
for i in range(1, H):
    next_row = [j for j, x in enumerate(table[i]) if x == "#"]
    if len(set(pre_row) & set(next_row)) == 1 and pre_row[-1] == next_row[0]:
        pre_row = next_row
    else:
        print('Impossible')
        exit()
print('Possible')
