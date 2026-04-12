# INPUT
h, w = map(int, input().split())
mapping = [list(input()) for i in range(h)]

# PROCESS

# 列をチェックして削除
def delete_row(mp):
  new_mp = []
  for row in mp:
    if ("#" in row):
      new_mp.append(row)
  return len(new_mp) < len(mp), new_mp

# 行をチェックして削除
def delete_column(mp):
  new_mp = []

  # 削除
  allow_columns = [0 for _ in range(len(mp[0]))]
  for row in mp:
    for cell_idx in range(len(row)):
      if (row[cell_idx] == "#"):
        allow_columns[cell_idx] = 1

  for row in mp:
    allow_row = []
    for cell_idx in range(len(row)):
      if (allow_columns[cell_idx] == 1):
        allow_row.append(row[cell_idx])
    new_mp.append(allow_row)

  return 0 in allow_columns, new_mp

deleted = True
while(deleted):
  deleted, mapping = delete_row(mapping)
  deleted, mapping = delete_column(mapping)

answer = mapping

# OUTPUT
for row in answer:
  print("".join(row))