# A - Restaurant

# N 今までに食べた食数
# x 今までに払った金額（円）
# y レストランからもらった金額（円）

N = int(input())
# print(N)

# x の計算 1食800円
x = N * 800
# print(x)

# y の計算 15食毎200円
y = int(N / 15) * 200
# print(y)

# x - y
answer = x - y

# 結果の表示
print(answer)
