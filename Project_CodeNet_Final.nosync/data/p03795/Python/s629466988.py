meal_fee=800
cash_back=200
cash_back_count=15
N=int(input())
x=N*meal_fee
y=int(N/cash_back_count) * cash_back
print(x-y)