n = int(input())
a = list(map(int, input().split()))

m = 1000000007

s = sum(a)
ans = 0
for i in range(n):
    aa = a[i]
    ans += aa * (s - aa)

ans = ans//2
ans = ans % m

print(ans)
