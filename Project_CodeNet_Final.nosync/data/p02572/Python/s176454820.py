n = int(input())
a = list(map(int,input().split()))
pans = 0
sum_ = sum(a)%(10**9+7)
for i in range(n-1):
    sum_ -= a[i]
    ans = sum_ * a[i]
    ans = ans % (10**9+7)
    pans += ans
print(pans%(10**9+7))