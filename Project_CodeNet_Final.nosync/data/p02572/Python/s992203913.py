n = int(input())
a = list(map(int, input().split()))
sum_a = sum(a)
calc = 0
for i in range(n):
    sum_a -= a[i]
    calc += ((sum_a % 1000000007) * a[i]) % 1000000007
calc %= 1000000007
print(calc)