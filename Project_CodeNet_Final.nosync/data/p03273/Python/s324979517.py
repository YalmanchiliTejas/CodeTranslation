H, W = map(int, input().split())
A = [input() for _ in range(H)]

#行の削除
for i in range(len(A)-1, -1, -1):
  if A[i].count(".") == len(A[i]):
        A.pop(i)

rm = []
#列の削除
for w in range(W):
  f = True
  for h in range(len(A)):
    if A[h][w] == "#":
        f = False
  if f:
    rm.append(w)

for r in range(len(rm)-1, -1, -1):
  for h in range(len(A)):
      A[h] = A[h][:rm[r]] + A[h][rm[r]+1:]

#出力
for a in A:
  print(a)