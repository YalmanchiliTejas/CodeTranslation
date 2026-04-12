num_ate_food = int(input())

total_cost = num_ate_food * 800
cash_back = 0

if num_ate_food >= 15:
    cash_back = (num_ate_food // 15) * 200

total_paid = total_cost - cash_back
print(total_paid)