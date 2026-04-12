n, k = map(int, input().split())


ans = 0
for i in range(2, n+1):
    if i-1 < k:
        continue
    else:
        #print((i-k)*(n//i), n % i-(i-k))
        ans += (i-k)*(n//i)
        ans += max(0, n % i-(k-1))

if k == 0:
    ans+=1
print(ans)
