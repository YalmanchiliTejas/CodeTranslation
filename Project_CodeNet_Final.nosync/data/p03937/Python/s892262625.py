import sys
readline = sys.stdin.readline

H,W = map(int,readline().split())
r = 0
for i in range(H):
  r += readline().rstrip().count("#")
  
if r != H + W - 1:
  print("Impossible")
else:
  print("Possible")
