# xの式： x = N * 800
# yの式： y = N // 15 * 200 '//で整数切り捨ての割り算

N = int(input())    # 食べた食事数Nを代入

x = N * 800 # 食事代xを計算

y = N // 15 * 200   # 15食毎の返金額yを計算

answer = x - y  # x - yの値

print(answer)