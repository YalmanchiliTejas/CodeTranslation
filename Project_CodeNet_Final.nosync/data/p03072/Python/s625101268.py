# n=int(input())
# a,b=map(int, input().split())
# c=list(map(int, input().split()))
# s=[list(map(int,list(input()))) for i in range(h)]  # 二次元配列入力　二次元マップみたいな入力のとき

# a=100
# b=0.987654321
# print('{0:06d}-{1:6f}'.format(a,b))  # 0埋めのときの出力
# 000100-0.987654

import numpy as np
import math
import copy

n=int(input())
h=list(map(int, input().split()))

num = 0

for i in range(len(h)):
    for j in range(len(h)):
        if i == j:
            num += 1
        if h[j] > h[i]:
            break

print(num)