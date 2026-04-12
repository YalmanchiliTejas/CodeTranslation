n=int(input())
a=list(map(int,input().split()))
ans=0
h=0
for i in range(0,n):
    if h<=a[i]:
        ans+=1
        h=a[i]
print(ans)
