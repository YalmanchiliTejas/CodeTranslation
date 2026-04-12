# C
n = int(input())
a = list(map(int, input().split()))

# 累積和ベクトルbを作成
a.reverse()
b = [0]*n
b[0] = a[0]
for i in range(1, n):
    b[i] = b[i-1]+a[i]
a.reverse()
b.reverse()

ans = 0
for i in range(n-1):
    ans += a[i]*b[i+1]

print(ans % (10**9+7))
