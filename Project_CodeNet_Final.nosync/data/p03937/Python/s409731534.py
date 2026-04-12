h,w = map(int, input().split())
s = []
sh = 0
for i in range(h):
  t = input()
  sh += t.count('#')
  s.append(t)
if sh == h+w-1:
  print ('Possible')
else:
  print ('Impossible')