n,k=map(int,input().split())
ans=0
if k==0:
    print(n**2)
    exit()

for b in range(1,n+1):
    if k>b-1:
        continue
    ans+=n//b*(b-k)
    ans+=max(n-n//b*b+1-k,0)

print(ans)