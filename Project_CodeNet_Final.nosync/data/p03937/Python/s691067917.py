"""
i-1行目の右端のマスとi行目の左端のマスが隣接しており、
それらの行においてはそれ以外のマスは隣接していないこと。

以上を満たした場合に'Possible'を出力すればよさそう。
"""
H, W = map(int, input().split())
table = [input() for _ in range(H)]
for i in range(1, H):
    li_pre = [i for i, x in enumerate(table[i - 1]) if x == "#"]
    li_now = [i for i, x in enumerate(table[i]) if x == "#"]
    if len(set(li_pre) & set(li_now)) == 1 and li_pre[-1] == li_now[0]:
        continue
    else:
        print('Impossible')
        exit()
print('Possible')
