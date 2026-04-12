n=int(input())
a=list(map(int,input().split()))
cnt=0
ans=0
for i in a:
  if cnt<=i:
    ans+=1
    cnt=i
print(ans)