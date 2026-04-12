n = int(input())
a_list = list(map(int, input().split()))

MOD = (10**9)+7
a_sum = 0
ans = 0
for i in range(n-1):
    a_sum += a_list[n-i-1]
    ans += a_sum * a_list[n-i-2]
    ans = ans % MOD

print(ans)
