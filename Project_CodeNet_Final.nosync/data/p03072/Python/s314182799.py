N=int(input())
H=list(map(int,input().split()))
ans=0
e=0
for i in range(0,N):
    for b in range(0,i):
        if H[i]<H[b]:
            e=1
            break
    if e==0:
        ans+=1
    e=0
print(ans)

