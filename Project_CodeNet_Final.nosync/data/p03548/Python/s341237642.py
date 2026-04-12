X,Y,Z = [int(x) for x in input().split()]
X = X-Z
ans = 0
cnt= 0
for i in range(10**9):
  if ans+Y+Z<=X:
    cnt+=1
    ans+=Y+Z
  else:
    print(cnt)
    exit()