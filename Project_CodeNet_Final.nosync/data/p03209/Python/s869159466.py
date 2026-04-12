N, X = [int(a) for a in input().split()]
ans = 0
now_level = N
num_list = [2 ** (n + 2) - 3 for n in range(N + 1)]
while X > 0:
    if X <= now_level:
        break
    num_list = [2 ** (n + 2) - 3 for n in range(now_level + 1)]
    plus_base = [a + now_level - b for a, b in zip(num_list, range(now_level + 1))]
    eat_num = max([a for a in plus_base if a <= X])
    eat_level = plus_base.index(eat_num)
    now_level = eat_level
    ans += int((num_list[eat_level] + 1) / 2 + 0.1)
    X -= eat_num
    if X > 0:
        X -= 1
        ans += 1
print(str(ans))