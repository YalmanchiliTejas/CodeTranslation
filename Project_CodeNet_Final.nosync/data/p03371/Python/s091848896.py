n = list(map(int,input().split()))
price = []

# 場合分けしていくのは大変そうだった
for i in range(max(n[3], n[4]) + 1):
    temp = 2 * i * n[2]
    if n[3] - i > 0:
        temp += (n[3] - i) * n[0]
    if n[4] - i > 0:
        temp += (n[4] - i) * n[1]

    # 十分に大きい数値を最初用意して，2値を比較し小さい方を変数に入れる方がいいかも
    price.append(temp)

print(min(price))