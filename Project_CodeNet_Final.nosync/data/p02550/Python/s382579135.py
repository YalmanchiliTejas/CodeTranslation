N, X, M = map(int, input().split())
checked = [-1] * M
a = X
i = 0
while checked[a] == -1 and i < N:
    checked[a] = i
    a = a**2 % M
    i += 1

if i == N:
    a = X
    ans = 0
    for _ in range(N):
        ans += a
        a = a**2%M
    print(ans)
else:
    cycle_size = i - checked[a]
    cycle_num = a
    cycle = []
    cycle_sum = 0
    for _ in range(cycle_size):
        cycle.append(cycle_num)
        cycle_sum += cycle_num
        cycle_num = cycle_num**2 % M

    before_cycle_size = checked[a] 
    before_cycle = []
    before_cycle_sum = 0
    num = X
    for _ in range(before_cycle_size):
        before_cycle.append(num)
        before_cycle_sum += num 
        num = num**2 % M
    ans = before_cycle_sum
    ans += (N-before_cycle_size)//cycle_size * cycle_sum
    after_cycle_size = (N-before_cycle_size)%cycle_size
    for i in range(after_cycle_size):
        ans += cycle[i]
    
    print(ans)