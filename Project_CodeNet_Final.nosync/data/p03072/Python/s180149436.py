N=int(input())
a=list(map(int,input().split()))

ans=1
for i in range(1,N):
    if a[i]>=max(a[:i]) : ans+=1
        
print(ans)