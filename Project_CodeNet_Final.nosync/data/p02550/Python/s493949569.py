N, X, M = map(int, input().split())

if N < M:
    ans = 0
    val = X
    for i in range(N):
        ans += val
        val = (val%M)*(val%M)%M
        
    print(ans)
    exit()

until_start_loop = 0
loop_len = 0
cum_sum = [0]
until_start_loop_sum = 0
loop_sum = 0

ls = [0]*M
val = X
cnt = 0 #TimeStamp
while True:
    if ls[val]:
        until_start_loop = ls[val] - 1
        loop_len = cnt - until_start_loop
        # until_start_loop -= 1
        until_start_loop_sum = cum_sum[until_start_loop]
        loop_sum = cum_sum[cnt] - until_start_loop_sum
        break
    cnt += 1
    ls[val] = cnt
    cum_sum.append(cum_sum[-1] + val)
    val = (val%M)*(val%M)%M


how_many_loop = (N-until_start_loop)//(loop_len)
ans = until_start_loop_sum + how_many_loop * loop_sum
remained = N - how_many_loop * loop_len - until_start_loop
ans += cum_sum[until_start_loop + remained] - cum_sum[until_start_loop]
print(ans)