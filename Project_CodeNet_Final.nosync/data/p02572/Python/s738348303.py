n = int(input())
a = list(map(int, input().split()))

ans = 0

a_goketi = sum(a)
b = []

for i in range(n):
    b.append(a_goketi - a[i])
    a_goketi -= a[i]

    ans += a[i] * b[i] 

ans %= 1000000007
print(ans)