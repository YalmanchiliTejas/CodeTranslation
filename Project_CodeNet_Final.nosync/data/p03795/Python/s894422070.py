# -*- coding: utf-8 -*-
# スペース区切りの整数の入力
x = int(input())
#x, y = map(int, input().split())
y = x//15
z = 800 * x - 200 * y

print("{0}".format(str(z)))