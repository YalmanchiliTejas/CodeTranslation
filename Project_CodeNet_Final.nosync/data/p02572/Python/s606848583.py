n = int(input())
a = list(map(int, input().split()))
sum_a = sum(a) * sum(a)
for i in range(n):
    sum_a -= a[i] * a[i]
sum_a = sum_a // 2
print(sum_a % (1000000000 + 7))