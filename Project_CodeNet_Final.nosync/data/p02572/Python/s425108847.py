n = int(input())
a_list = list(map(int, input().split()))
sum_a = sum(a_list)
ans = 0
m = 10 ** 9 + 7

for i in range(n):
    sum_a -= a_list[i]
    ans += a_list[i] * sum_a
    ans %= m

print(ans)
