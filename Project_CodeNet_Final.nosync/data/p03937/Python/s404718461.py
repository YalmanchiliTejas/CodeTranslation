H, W = map(int, input().split())
moves = 0
for h in range(H):
  S = str(input())
  for s in S:
    if s == '#':
      moves += 1

if moves == H + W - 1:
  print('Possible')
else:
  print('Impossible')