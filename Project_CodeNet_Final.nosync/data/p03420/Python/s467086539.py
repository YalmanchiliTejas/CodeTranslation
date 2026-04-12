n , k = map(int,input().split())
ans = 0
if k == 0:
    ans = n**2
else:
    for b in range(k+1,n+1):
        ans += ((n-b+1)//b + 1)*(b-k)
        if k - 1 < n % b < b-1:
            ans += n % b - k + 1
print(ans)