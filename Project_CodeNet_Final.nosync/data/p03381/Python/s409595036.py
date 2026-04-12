N = int(input())
X = list(map(int,input().split()))
newX = []
for i in range(N):
  newX.append((X[i],i))
newX.sort()
ans = [0]*N
f = N//2-1
l = N//2
for i in range(N):
  num, ind = newX[i]
  if i < l:
    ans[ind] = newX[l][0]
  else:
    ans[ind] = newX[f][0]
for j in ans:
  print(j)


