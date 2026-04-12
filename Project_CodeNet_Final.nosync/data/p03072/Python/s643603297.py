n=int(input())
h=list(map(int,input().split()))
ans=0
for i in range(n):
    fl=0
    for j in range(i):
        if(h[j]>h[i]):
            fl=1
            break
    if(fl==0):
        ans+=1
print(str(ans))
