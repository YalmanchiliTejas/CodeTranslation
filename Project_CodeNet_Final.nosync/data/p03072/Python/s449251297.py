n=int(input())
h=list(map(int, input().split()))

ans=1
a=0

for i in range(1,n):
    for k in range(i):
        if h[k]>h[i]:
            a=1
    
    if a==0:
        ans+=1
    
    a=0
    
print(ans)