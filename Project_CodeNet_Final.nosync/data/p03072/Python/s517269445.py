# -*- coding: utf-8 -*-
# 整数の入力
a = int(input())
# スペース区切りの整数の入力
l = list(map(int, input().split()))
# 文字列の入力

cnt = 1
for i, v in enumerate(l):
  if i >= 1:
    #print(i,v)
    #print(l[:i])
    if max(l[:i]) <= v:
      cnt += 1

print(cnt)
# 出力
#print("{} {}".format(l, a))