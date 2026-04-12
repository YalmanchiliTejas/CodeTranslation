#何回食べたか入力を受け取る
number = int(input())
#単価800円×回数
x = 800 * number
#15で割った商×200円
y = number // 15 * 200

total_price = x-y
print(total_price)
