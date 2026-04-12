N,X = (int(x) for x in input().split())

b_num_arr = [1]
p_num_arr = [1]
for i in range(1, 51):
    b_num_arr.append(b_num_arr[-1]*2+3)
    p_num_arr.append(p_num_arr[-1]*2+1)


def burger_eat(n, x):
    if x == 0:
        return 0
    if n == 0:
        return 1
    x -= 1
    if x < b_num_arr[n-1]:
        return burger_eat(n-1, x)
    pre_eat = p_num_arr[n-1]
    x -= b_num_arr[n-1]
    if x == 0:
        return pre_eat
    x -= 1
    pre_eat += 1
    return pre_eat + burger_eat(n-1, x)

ans = burger_eat(N, X)

print(ans)
