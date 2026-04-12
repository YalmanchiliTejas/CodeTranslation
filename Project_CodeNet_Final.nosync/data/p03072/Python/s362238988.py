n=int(input())
lis=list(map(int,input().split()))
ans=0
 
 
for i in range(1,n):
    if max(lis[:i])<=lis[i]:
        ans+=1
 
print(ans+1)