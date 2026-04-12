n = int(input())
a = list(map(int, input().split()))
a.reverse

sum_until_here = 0
ans_sum = 0
for i in range(n):
    ans_sum += a[i] * sum_until_here
    sum_until_here += a[i]
print(ans_sum % (1000000000 + 7))