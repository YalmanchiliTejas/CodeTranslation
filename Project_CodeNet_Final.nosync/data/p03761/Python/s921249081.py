import numpy as np
n = int(input())
S = [input() for i in range(n)]
mat = [[0 for i in range(26)] for j in range(n)]
mat = np.array(mat)
for i in range(n):
	Sp = S[i]
	for j in range(len(Sp)):
		mat[i][ord(Sp[j])-97] += 1
result = ''
for i in range(26):
	Cnt = min(mat[:,i])
	for j in range(Cnt):
		result += chr(i+97)
print(result)