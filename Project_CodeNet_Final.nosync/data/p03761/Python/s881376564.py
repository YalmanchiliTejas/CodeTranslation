# -*- coding: utf-8 -*-

import os
import sys
import math
import numpy as np

n = int(input())

S = [input() for i in range(n)]

N = 26

alphabet = [chr(i) for i in range(65+26+6,65+26+26+6)]

# print(n)
M = np.zeros([n, 26])

offset = ord('a')

for i, strr in enumerate(S):
    for c in strr:
    	M[i, ord(c)-offset] += 1

ans = np.zeros(N)
for i in range(N):
	ans[i] = np.min(M[:, i])
# print(ans)
var = ''

for i, num in enumerate(ans):
	# print(a)
	for j in range(int(num)):
		var += alphabet[int(i)]

print(var)