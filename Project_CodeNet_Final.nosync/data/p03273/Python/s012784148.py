H,W = map(int,input().split())

list_grid = []
for i in range(H):
  list_grid.extend(list(input().split()))

# 行を見る
for i, record in enumerate(list_grid):
  if record == '.' * W:
    list_grid[i] = ''

list_grid = list(filter(lambda s:len(s)>0, list_grid))

import copy
ans = copy.copy(list_grid)

# 列を見る
row = 0
flg = True
while flg:
  tmp = []
  for record in ans:
    tmp.append(record[row])
  
  # 対象列に白しかない場合、その列を削除
  if not ('#' in tmp):
    for i in range(len(ans)):     
      ans[i] = ans[i][:row] + ans[i][row+1:]
  else:
    row += 1
      
  if row == len(ans[0]):
    flg = False


# 出力
for record in ans:
  print(record)