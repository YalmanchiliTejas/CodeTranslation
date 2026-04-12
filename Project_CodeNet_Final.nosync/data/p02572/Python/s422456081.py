N = int(input())
A_list = list(map(int, input().split()))
A_list.insert(0, 0)

cum_sum = 0
cum_sum_list = []
for i in range(N + 1):
    cum_sum += A_list[i]
    cum_sum_list.append(cum_sum)

ans = 0
for i in range(1, N+1):
    ans += A_list[i] * (cum_sum_list[N] - cum_sum_list[i])
    ans = ans % 1000000007
print(ans)