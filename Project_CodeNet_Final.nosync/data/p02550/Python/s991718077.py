n,x,m=map(int,input().split())

used=[0]*m
used[x]=1
cnt=1
y=x
while True:
    y=y**2
    y%=m
    cnt+=1

    if used[y]>0:
        loopst=used[y]
        loopend=cnt-1
        break
    
    used[y]=cnt

ans=0
loopsum=0
beforesum=0
for i in range(m):
    if loopst<=used[i]<=loopend:
        loopsum+=i
    if 0<used[i]<loopst:
        beforesum+=i

if n>loopend:
    n-=loopst-1
    ans+=beforesum
    ans+=n//(loopend-loopst+1)*loopsum
    n%=(loopend-loopst+1)
    
    for i in range(m):
        if used[i]==loopst:
            x=i
            break

for i in range(n):
    ans+=x
    x=x**2
    x%=m

print(ans)
