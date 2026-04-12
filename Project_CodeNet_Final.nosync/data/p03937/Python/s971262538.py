h,w = map(int,input().split())
a = [list(input()) for nesya in range(h)]
c = 0
for i in range(h):
  for j in range(w):
    if a[i][j] == '#':
      c += 1

if c == h+w-1:
  print('Possible')
else:
  print('Impossible')