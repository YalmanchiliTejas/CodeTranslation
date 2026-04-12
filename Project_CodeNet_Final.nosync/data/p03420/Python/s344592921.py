n, k = map(int, input().split())
ans = 0
if k == 0:
    ans = n*n
else:
    for i in range(1, n+1):
        ans += n//i * max(i-k, 0)
        a = n//i * max(i-k, 0)
        b = 0
        if i >= k and n % i != 0:
            ans += max(0, (n%i+1)-k)
            b = max(0, (n%i+1)-k)
print(ans)
