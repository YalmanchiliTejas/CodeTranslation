h,w = map(int,input().split())
aa = [list(input()) for _ in range(h)]

use_cols = []
use_rows = []

for hi in range(h):
  flag = False
  for wi in range(w):
    if aa[hi][wi] == '#':
      flag = True
      break
  if flag:
    use_rows.append(hi)

for wi in range(w):
  flag = False
  for hi in range(h):
    if aa[hi][wi] == '#':
      flag = True
      break
  if flag:
    use_cols.append(wi)
    
ans = [[' ']*(w-len(use_cols)) for _ in range(h-len(use_rows))]

ans =[]
for hi in use_rows:
  row = ''
  for wi in use_cols:
    row+=aa[hi][wi]
  ans.append(row)
  
for a in ans:
  print(a)  