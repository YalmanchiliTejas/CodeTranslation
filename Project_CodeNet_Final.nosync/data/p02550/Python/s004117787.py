N, X, M = map(int, input().split())
mod_appeared = [False] * M
A_cycle = [X]
mod_appeared[X] = True
A = X * X % M
while not mod_appeared[A]:
    A_cycle.append(A)
    mod_appeared[A] = True
    A = A * A % M


if N < len(A_cycle):
    print(sum(A_cycle[:N]))
    exit()

cycle_start = A_cycle.index(A)
cycle_len = len(A_cycle) - cycle_start
cycle_sum = sum(A_cycle[cycle_start:])
prefix_sum = sum(A_cycle[:cycle_start])

q, r = divmod(N - cycle_start, cycle_len)
ans = prefix_sum + q * cycle_sum + sum(A_cycle[cycle_start:cycle_start + r])
print(ans)
