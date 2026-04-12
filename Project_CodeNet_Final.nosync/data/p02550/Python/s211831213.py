N, X, M = map(int, input().split())
Memo = [-1] * M
Cumsum = [0] * M
cumsum = X
x = X

for i in range(N):
    if Memo[x] != -1:
        break
    Memo[x] = i
    Cumsum[x] = cumsum
    x = x * x % M
    cumsum += x
else:
    print(cumsum-x)
    exit()
loop_length = i - Memo[x]
init_sum = Cumsum[x]
loop_sum = cumsum - init_sum

n_from_init = N - i - 1
n_loops, n_from_loopend = divmod(n_from_init, loop_length)
cumsum += n_loops * loop_sum

for i in range(n_from_loopend):
    x = x * x % M
    cumsum += x

print(cumsum)
