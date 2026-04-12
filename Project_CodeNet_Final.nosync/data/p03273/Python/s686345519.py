H,W = map(int, input().split())
A = []
B = []
for i in range(H):
  a = list(input())
  if a != ["."]*W:
    A.append(a)
for i in range(W):
  cnt = 0
  for j in range(len(A)):
    if A[j][i] != ".":
      cnt += 1
  if cnt == 0:
    B.insert(0,i)
for i in range(len(A)):
  for j in range(len(B)):
    del A[i][B[j]]
for i in range(len(A)):
  ans = "".join(A[i])
  print(ans)