n=int(input())
h=list(map(int,input().split()))
ans=1
for i in range(n-1):
    if max(h[:i+1])<=h[i+1]:
        ans+=1
print(ans)
