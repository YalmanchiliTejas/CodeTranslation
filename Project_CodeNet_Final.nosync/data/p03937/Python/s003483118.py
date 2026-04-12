H,W = map(int,input().split())
c = 0
for i in range(H):
  A = input()
  c += A.count("#")
if c == H+W-1:
  print("Possible")
else:
  print("Impossible")