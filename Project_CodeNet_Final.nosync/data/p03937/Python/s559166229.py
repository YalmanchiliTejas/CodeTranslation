h, w = [ int(v) for v in input().split() ]

v = 0
for i in range(h):
  v += input().count("#")
  
if v == h + w - 1:
  print("Possible")
else:
  print("Impossible")