n = int(input())
a = list(map(int, input().split()))
mod = 1000000007
total = 0
sum_sqr = 0
sqr_sum = 0
for i in range(n):
    sum_sqr = (sum_sqr + a[i])
sum_sqr = (sum_sqr * sum_sqr)
for i in range(n):
    sqr_sum = (sqr_sum + ((a[i] * a[i])))
# print(sqr_sum, sum_sqr)
total = (sum_sqr - sqr_sum) // 2
print(total%mod)