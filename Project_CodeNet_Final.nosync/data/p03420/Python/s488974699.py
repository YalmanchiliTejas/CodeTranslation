n,k = map(int,input().split())
ans = 0
if k == 0:
    for x in range(1,n+1):
        ans += n//x
    k += 1
for b in range(k,n+1):
    m = int((n+1)/b)
    ans += m*(b-k)
    ans += max(0,n-m*b-k+1)

print(ans)