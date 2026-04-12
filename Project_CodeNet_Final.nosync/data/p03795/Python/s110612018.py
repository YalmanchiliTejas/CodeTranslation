# 入力
N = int(input())

# 処理

total_pay = 800 * N
total_get =N // 15 * 200

# 出力
answer = total_pay - total_get
print(answer)
