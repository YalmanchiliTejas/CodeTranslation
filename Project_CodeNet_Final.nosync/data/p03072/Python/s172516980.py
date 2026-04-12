n=int(input())
h = list(map(int,input().split()))
 
ans=1
cnt=0
for i in range(n-1):
  for j in range(i+1):
    if h[j]<=h[i+1]:
      cnt+=1
    else:
      cnt=0
      break
    if cnt==i+1:
      ans+=1
      cnt=0
      break
 
print(ans)