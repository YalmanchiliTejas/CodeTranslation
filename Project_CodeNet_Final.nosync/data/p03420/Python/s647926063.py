n,k = map(int,input().split())

ans = 0

if k == 0:
    print(n**2)
    exit()

for i in range(k+1,n+1):
    a = n // i
    b = n % i
    tmp = a * (i - k) + max(0, b - k + 1)
    ans += tmp

print(ans)
