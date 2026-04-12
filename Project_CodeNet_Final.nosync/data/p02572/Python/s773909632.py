n = int(input())
a = list(map(int,input().split()))

ans = 0

sum_a = sum(a)


for i in range(n):
    ans += a[i] * (sum_a - a[i])
    sum_a -= a[i]

print(ans%(10 ** 9 + 7))