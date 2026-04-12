n=int(input())
a=list(map(int,input().split()))
ans=1
for i in range(n-1):
    maxim=max(a[0:i+1])
    if a[i+1]>=maxim:
        ans+=1
print(ans)