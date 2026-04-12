n=int(input())
H=list(map(int,input().split()))
ans=0
for i in range(n):
  if max(H[:i+1])==H[i]:
    ans+=1
print(ans)