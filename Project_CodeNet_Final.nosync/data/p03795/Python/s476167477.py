#   AtCoder abc055 a

#   入力
n = int(input())

#   処理
total_pay = n * 800
total_back = (n // 15) * 200
balance = total_pay - total_back
#   出力
print(balance)

