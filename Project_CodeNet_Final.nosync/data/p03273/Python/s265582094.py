H,W = map(int, input().split())
a = [input() for _ in range(H)]

del_lst = []
# 横の削除
for i in range(H):
  for j in range(W):
    if a[i][j] == '#':
      break
  else:
    del_lst.append(i)

# 削除
for i in sorted(del_lst,reverse=True):
  a.pop(i)

# 列の削除
del_lst = []
for i in range(len(a[0])):
  for j in range(len(a)):
    if a[j][i] == '#':
      break
  else:
    del_lst.append(i)

# 削除
for i in sorted(del_lst,reverse=True):
  for j in range(len(a)):
    str = list(a[j])
    str.pop(i)
    a[j] = ''.join(str)

for _a in a:
  print(_a)