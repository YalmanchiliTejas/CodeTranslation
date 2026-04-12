n=int(input())
a_list = list(map(int,input().split()))

mod = 10**9 + 7

a_sum = sum(a_list)

ans = 0
for i in range(0, n):
    ans += (a_list[i] * (a_sum - a_list[i]))
ans = ans // 2
print(ans % mod)