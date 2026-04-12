# h wの読み込み
h, w = map(int, input().split())
# 行列作成
mat = [input() for _ in range(h)]

# #が含まれていない行を削除
[mat.remove(row) for row in mat[::-1] if ("#" not in row)]
# #が含まれている列のインデックスを取得
showCol = [i for i in range(w) if "#" in [row[i] for row in mat]]

# 表示
print("\n".join(["".join([row[c] for c in showCol]) for row in mat]))
