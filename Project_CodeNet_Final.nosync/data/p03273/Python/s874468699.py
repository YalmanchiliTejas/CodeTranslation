H, W = [int(hw) for hw in input().split()]
A = []
for h in range(H):
  a = [a for a in input()]
  if a.count("#") > 0:
    A.append(a)

for w in reversed(range(W)):
  cnt = 0
  for h in range(len(A)):
    if A[h][w] == ".":
      cnt += 1
  if cnt == len(A):
    for h in range(len(A)):
      del A[h][w]

for h in range(len(A)):
  ans = "".join(A[h])
  print(ans)