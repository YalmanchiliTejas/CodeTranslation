n=int(input())
a=list(map(int,input().split()))
ans=0
for i in range(n):
    k=0
    for j in range(i):
        if(a[i]<a[j]):
            k=1
    if(k==0):
        ans+=1
print(ans)
        