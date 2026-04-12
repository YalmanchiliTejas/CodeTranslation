a_price, b_price, c_price, a_target, b_target = map(int, input().split())

i = 0
i_max = 0
ans = float("inf")

if a_target > b_target:
    i_max = a_target
else:
    i_max = b_target

for i in range(0, i_max + 1):
    sum = i * c_price * 2 + max(0, a_target - i) * a_price + max(0, b_target - i) * b_price
    if sum < ans:
        ans = sum

print(ans)