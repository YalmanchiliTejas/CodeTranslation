N, X, M = map(int, input().split())

if X == 0:
    print(0)
    exit()

A_history = [-1] * M
sum_history = [0] * (M + 1)
A = X
all_sum = A

sum_history[0] = A

for i in range(M):
    Anext = (A * A) % M
    all_sum += Anext
    sum_history[i + 1] = all_sum
    if A_history[A] == -1:
        A_history[A] = i
    else:
        break
    A = Anext

if i >= N:
    print(sum_history[N - 1])
else:
    cycle_start = A_history[A]
    cycle_end = i - 1
    cycle_length = cycle_end - cycle_start + 1
    cycle_time = N - cycle_start
    cycle_count = cycle_time // cycle_length
    cycle_mod = cycle_time % cycle_length
    ans = sum_history[cycle_start] + (sum_history[cycle_end + 1] - sum_history[cycle_start]) * cycle_count + \
          (sum_history[cycle_start + cycle_mod - 1] - sum_history[cycle_start])
    print(ans)
