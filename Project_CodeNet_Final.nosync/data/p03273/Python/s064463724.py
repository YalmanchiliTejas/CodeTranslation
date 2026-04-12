H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]
a_h = [False]*H
a_w = [False]*W

for i in range(H):
  for j in range(W):
    if a[i][j] == '#':
      a_h[i] = True
      a_w[j] = True

for i in range(H):
  if a_h[i] == True:
    for j in range(W):
      if a_w[j] == True:
        print(a[i][j],end='')
    print()

  