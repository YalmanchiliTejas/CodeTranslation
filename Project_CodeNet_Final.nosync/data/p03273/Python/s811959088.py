h,w = map(int,input().split())
a = [[i == "#" for i in list(input())] for _ in range(h)]
line,row = [0]*w,[0]*h
for i in range(h):
  for j in range(w):
    if a[i][j]:
      line[j] = 1
      row[i] = 1
for i in range(h):
  if not row[i]:
    continue
  ans = ""
  for j in range(w):
    if line[j]:
      ans += "#"*a[i][j]+"."*(not a[i][j])
  print(ans)