# -*- coding: utf-8 -*-
# スペース区切りの整数の入力
r, g, b = map(str, input().split())
# 文字列の入力
#s = input()
#開業されたN個要素を受け付ける
#list = [input() for i in range(N)]
a = ("").join([r, g, b])
if int(a)%4==0:
    print("YES")
else:
    print("NO")
