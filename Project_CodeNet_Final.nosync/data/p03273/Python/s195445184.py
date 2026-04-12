import numpy as np

H, W = map(int, input().split())

ans = []
for i in range(H):
  ans.append(input())
  
ind = []
k = len(ans)
for i, ss in enumerate(reversed(ans)):
  if ss == "." * W:
    ind.append(k-i-1)
  
index = []
for i in range(H):
  for j in range(W):
    if ans[i][j] == "#":
      index.append(j)

for i in range(H):
  if i in ind:
    continue
  aaa = ""
  for j in range(W):
    if j in index:
      aaa += ans[i][j]
      
  print(aaa)
      