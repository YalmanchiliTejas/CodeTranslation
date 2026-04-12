h,w = map(int,input().split())
a = [list(input()) for _ in range(h)]

delete_column = [True]*w
delete_row = [True]*h
for i in range(h):
  for j in range(w):
    if a[i][j] == '#':
      delete_column[j] = False
      delete_row[i] = False
for i in range(h):
  if not delete_row[i]:
    ans = ''
    for j in range(w):
    	if not delete_column[j]:
          ans += a[i][j]
    print(ans)
