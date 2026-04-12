n = int(input())
a = [int(i) for i in input().split()]
ans = 0
b = sum(a)
for i in range(n):
    b -= a[i]
    ans += (a[i]*b)
    ans = ans % (10**9+7)
print(ans)