n=int(input())
li=list(map(int,input().split()))
mx=0
ans=0
for i in li:
  if mx<=i:
    mx=i
    ans+=1
print(ans)