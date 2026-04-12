H,W = [int(x) for x in input().split()]
ans = []
for i in range(H):
  cnt= 0
  S = list(input())
  for j in range(W):
    if S[j]==".":
      cnt +=1
  if cnt!=W:
    ans.append(S)
ans1 = []
for j in range(len(ans[0])):
  cnt = 0
  for i in range(len(ans)):
    if ans[i][j]==".":
      cnt+=1
  if cnt ==len(ans):
    ans1.append(j)
for i in range(len(ans)):
  for j in ans1:
    ans[i][j]=0
for i in range(len(ans)):
  for j in range(len(ans[0])):
    if ans[i][j] !=0:
    	print(ans[i][j],end="")
  print()