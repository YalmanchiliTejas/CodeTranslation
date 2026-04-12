n,k = map(int,input().split())
ans = 0

if k > 0:
    for i in range(k+1,n+1):
        a = n // i
        b = n % i
        ans += (a * (i-k) + (max(0,b-(k-1))))
else:
    ans = n ** 2
    
print(ans)