H,W = map(int, input().split())
A = [[0 for _ in range(W+1)] for _ in range(H+1)]
for h in range(H):
  l = input()
  for w in range(W):
    A[h][w] = 0 if l[w] == '.' else 1
for h in range(H):
  n = 0
  for w in range(W):
    n += A[h][w]
  A[h][W] = n
for w in range(W):
  n = 0
  for h in range(H):
    n += A[h][w]
  A[H][w] = n
for h in range(H):
  if A[h][W] == 0: continue
  ans = []
  for w in range(W):
    if 0 < A[H][w]:
      ans.append('.' if A[h][w] == 0 else '#')
  print(''.join(map(str,ans)))
