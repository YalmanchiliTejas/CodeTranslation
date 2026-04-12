H, W = map(int, input().split())
A = [input() for _ in range(H)]

c = 0
for i in range(H):
  c += A[i].count('#')

if c == H+W-1:
  print('Possible')
else:
  print('Impossible')
