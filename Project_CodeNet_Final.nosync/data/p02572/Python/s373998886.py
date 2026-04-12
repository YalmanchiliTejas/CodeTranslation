n = int(input())
a = list(map(int, input().split()))

sum_a = 0
sum_i = sum(a)

for i in range(n-1):
    sum_i -= a[i]
    sum_a += (a[i] * sum_i)

print(sum_a%((10 **9)+7))