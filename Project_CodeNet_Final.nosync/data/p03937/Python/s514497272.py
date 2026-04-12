h, w = map(int, input().split())

rc = 0
for _ in range(h):
  rc += input().count('#')

if rc == w+h-1:
  print('Possible')
else:
  print('Impossible')