n = int(input())
a = [int(input()) for i in range(n)]

a.sort()

ans = 0

for i in range(n):
    if n%2==0:
        if i<n//2-1:
            ans-=a[i]*2
        if i==n//2-1:
            ans-=a[i]
        if i==n//2:
            ans+=a[i]
        if i>n//2:
            ans+=a[i]*2
    else:
        if i<n//2-1:
            ans-=a[i]*2
        if i>n//2+1:
            ans+=a[i]*2

if n%2==1:
    if a[n//2+1]-a[n//2]>a[n//2]-a[n//2-1]:
        ans += a[n//2+1]*2-a[n//2]-a[n//2-1]
    else:
        ans += a[n//2+1]+a[n//2]-a[n//2-1]*2

print(ans)