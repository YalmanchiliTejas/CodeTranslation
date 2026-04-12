H, W = map(int,input().split())

A = [str(input()) for _ in range(H)]

LH = set([])
LW = set([])

for i in range(H):
  for j in range(W):
    if A[i][j] == "#":
      LH.add(i)
      LW.add(j)

UH = len(LH)
ans = []
for i in LH:
  temp = ""
  for j in LW:
    #print(i,j,A[i][j])
    temp += A[i][j]
  ans.append(temp)
print(*ans, sep="\n")