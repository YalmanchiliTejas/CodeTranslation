N, X, M = map(int, input().split())
record_sum = [0, ]
flag = [False for _ in range(M)]
An = X

# n=1
record_sum.append(An)
flag[An] = 1

for i in range(2, M + 2):
    An = pow(An, 2, M)  # 　(An ** 2) % Mと等価
    record_sum.append(record_sum[-1] + An)

    if flag[An]:
        start_index = flag[An]
        initial_cost = record_sum[start_index - 1]
        cycle_cost = record_sum[-1] - record_sum[start_index]
        cycle_length = i - start_index
    else:
        flag[An] = i

if start_index >= N:
    print(record_sum[N])

else:
    ans = 0
    ans += ((N - start_index) // cycle_length) * cycle_cost
    ans += record_sum[(N - start_index) % cycle_length + start_index]

    print(ans)
