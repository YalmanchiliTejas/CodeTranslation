h, w = map(int, input().split())
a = [''] * h
# 行の数だけ入力
for i in range(h):
  a[i] = input()

row = [False] * h
col = [False] * w

# 各セルについてTrue/Falseを設定
for i in range(h):
  for j in range(w):
    if a[i][j] == "#":
      row[i] = True
      col[j] = True

# 出力
for i in range(h):
  if row[i]:
    for j in range(w):
      if col[j]:
        print(a[i][j], end="")
    print()