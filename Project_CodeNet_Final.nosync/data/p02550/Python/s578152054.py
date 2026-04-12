n, x, m =  map(int, input().split())
ans = 0
loop_list = [0] * m
loop_list[x] = 1
order_list = [x]

for i in range(1, m + 1):
    x = pow(x, 2, m)
    if loop_list[x] != 1:
        loop_list[x] = 1
        order_list.append(x)
    else:
        break

index = order_list.index(x)
time = (n - index) // (len(order_list) - index)
mod = (n - index) % (len(order_list) - index)

ans += sum(order_list[:index])
ans += sum(order_list[index:]) * time
ans += sum(order_list[index:index + mod])

print(ans)
