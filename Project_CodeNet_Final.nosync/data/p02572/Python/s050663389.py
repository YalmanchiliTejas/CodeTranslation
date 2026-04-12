n = int(input())
a_list = [int(x) for x in input().split()]
a_sum = sum(a_list)
m = 10 ** 9 + 7
ans = 0
for i in range(n - 1):
    a_sum -= a_list[i]
    ans = (ans + a_list[i] * a_sum) % m
print(ans)