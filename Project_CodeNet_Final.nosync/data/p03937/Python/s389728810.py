H,W = map(int,input().split())
A=""
for i in range(H):
  A += input()

n=A.count("#")
if n==H+W-1:
  print("Possible")
else:
  print("Impossible")