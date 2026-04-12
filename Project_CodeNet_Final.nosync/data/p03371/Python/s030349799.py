money_a, money_b, money_c, num_a, num_b = [int(x) for x in input().strip().split()]
sum_money = list()
temp = 0
for _ in range(num_a):
    temp += money_a
for _ in range(num_b):
    temp += money_b
sum_money.append(temp)
temp = 0
for _ in range(min(num_a, num_b)):
    temp += money_c*2
if num_a > num_b:
    temp += money_a * (num_a-num_b)
elif num_a < num_b:
    temp += money_b * (num_b-num_a)
sum_money.append(temp)
temp = 0
for _ in range(max(num_a, num_b)):
    temp += money_c*2
sum_money.append(temp)
print(min(sum_money))