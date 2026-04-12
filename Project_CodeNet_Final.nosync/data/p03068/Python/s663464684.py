# -*- coding: utf-8 -*-
 
N = int(input())
S = input()
K = int(input())
 
result = ''
sk = S[K-1]

for s in S:
	if sk == s:
		result += s
	else:
		result += '*'
 
print(result)