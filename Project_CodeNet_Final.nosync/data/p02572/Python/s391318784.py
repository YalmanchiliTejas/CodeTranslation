n = int(input())
a = list(map(int, input().split()))

ans = 0
sum_ = sum(a)
for i in range(n):
    sum_ = sum_ - a[i]
    ans += a[i] *(sum_)
    res = ans % (10**9 + 7)
print(res)