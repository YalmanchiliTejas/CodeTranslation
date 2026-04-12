# 入力
N = int(input())

# (N食×800円) - (N割る15切り捨て*200円)
x = N * 800
y = N // 15 * 200
answer = x - y
print(answer)
