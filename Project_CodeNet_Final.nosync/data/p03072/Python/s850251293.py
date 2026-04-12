# -*- coding: utf-8 -*-
# 整数の入力
a = int(input())
# スペース区切りの整数の入力
mountains = list(map(int, input().split()))

height = mountains[0]
sum = 1
for i in range(1,a):
    if mountains[i] >= height:
        sum += 1
        height = mountains[i]

# 出力
print(sum)