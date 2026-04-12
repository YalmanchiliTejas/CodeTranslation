# -*- coding: utf-8 -*-
# スペース区切りの整数の入力
# b, c =
# a = int(input())
n = str(input())
#target_list = [int(i) for i in input().split()]

# 判定
if len(list(set(n)))==2:
    print("Yes")
else:
    print("No")
