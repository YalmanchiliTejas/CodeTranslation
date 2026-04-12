n , x = map(int, input().split())
l = 2**(n+2)-3

ans = 0
k=n
while l>=1:
    if x==(l+1)//2:
        ans+=2**(k)
        break
    if x==(l+1)//2-1:
        ans+=2**(k)-1
        break
    if x>(l+1)//2:
        ans+=2**(k)
        x-=(l+1)//2-1
    k-=1
    x-=1
    l=(l-1)//2-1
print(ans)
