# -*- coding: utf-8 -*-

import numpy as np

H, W = map(int, input().split())

masu = []
res = []
str1 = '.' * W

for i in range(H):
	str2 = input()
	if str1 != str2:
		masu.append(str2)

l = ['.'] * len(masu)
for i in range(W):
	tmp = [k[i] for k in masu]
	if tmp != l:
		res.append(tmp)

ww = len(res[0])
hh = len(res)
for i in range(ww):
	for j in range(hh):
		print(res[j][i], end='')
	print('')