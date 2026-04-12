H,W = map(int,input().split())
step = H+W-2
A = []
for i in range(H):
  temp = str(input())
  temp = list(temp)
  A.append(temp)
cnt = 0
for i in range(H):
  for j in range(W):
    if A[i][j] == "#":
      cnt += 1
if cnt == step+1:
  print("Possible")
else:
  print("Impossible")