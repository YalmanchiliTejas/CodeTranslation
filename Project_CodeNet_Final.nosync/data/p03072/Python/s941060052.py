N = int(input())
l = list(map(int,input().split()))
max_ = 0
ans = 1
for i in range(1,N):
  if l[i] >= max(l[:i]):
    ans+=1
print(ans)