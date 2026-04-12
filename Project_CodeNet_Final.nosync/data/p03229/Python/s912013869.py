n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
ans = [0]*2
for i in range(n):
    if i%2==0:
        ans[0] -= 2*a[i//2]
    else:
        ans[0] += 2*a[n-1-i//2]
    
    if i%2==0:
        ans[1] += 2*a[n-1-i//2]
    else:
        ans[1] -= 2*a[i//2]
if n%2==0:
    ans[0] +=a[n//2-1]
    ans[0] -=a[n//2]
    ans[1] +=a[n//2-1]
    ans[1] -=a[n//2]
else:
    ans[0] +=a[n//2]
    ans[0] +=a[n//2-1]
    ans[1] -=a[n//2]
    ans[1] -=a[n//2+1]
print(max(ans))