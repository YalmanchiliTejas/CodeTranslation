N = int(input())

a = list(map(int,input().split()))

ans = 0
sum = 0

for i in range(N):
    sum += a[i]

for i in range(N-1):
    sum -= a[i]
    ans += a[i]*sum

m = 10**9 + 7

ans = ans % m

print(ans)