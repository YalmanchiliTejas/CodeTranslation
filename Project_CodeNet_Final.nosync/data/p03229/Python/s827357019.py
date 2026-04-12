n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
ans =0
if n%2==0:
    ans = 2*(sum(a[n//2:])-sum(a[:n//2]))-a[n//2]+a[n//2-1]
else:
    ans = (sum(a[n//2:])-sum(a[:n//2]))*2 - a[n//2] - a[n//2+1]
    ans = max(ans,(sum(a[n//2+1:])-sum(a[:n//2+1]))*2 + a[n//2] + a[n//2-1])
print(ans)