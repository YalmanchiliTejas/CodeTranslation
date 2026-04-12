H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

count = 0
for i in range(H):
  for j in range(W):
    if A[i][j] == "#":
      count += 1

print("Possible" if count == H+W-1 else "Impossible")