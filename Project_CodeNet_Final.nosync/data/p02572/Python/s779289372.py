n = int(input())
a = list(map(lambda x: int(x) % (10**9+7), input().split()))
tsum = 0
isum = 0
for i in range(n):
    isum = (isum + a[i]) % (10**9+7)
for i in range(n-1):
    isum += (10**9+7) - a[i]
    tsum += (isum * a[i]) % (10**9+7)
print(tsum%(10**9+7))