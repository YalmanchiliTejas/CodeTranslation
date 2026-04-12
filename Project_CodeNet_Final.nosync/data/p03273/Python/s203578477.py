import warnings
import numpy as np
warnings.simplefilter(action='ignore', category=FutureWarning)

h, w = map(int,input().split())
table = np.empty((h,w))

for i in range(h):
	temp = [0 if x=="." else 1 for x in list(input())]
	for j in range(w):
		table[i][j] = temp[j]

new1 = table
# print(table)

c = 0

for i in range(h):
	if not 1 in table[i]:
		new1 = np.delete(new1, i-c, 0)
		c += 1

c = 0

for j in range(w):
	if not 1 in table[:,j]:
		new1 = np.delete(new1, j-c, 1)
		c += 1

table = new1
# print(table)

for i in range(len(table)):
	z = ""
	for j in range(len(table[0])):	
		if table[i][j] == 0:
			z = z + "."
		else:
			z = z + "#"
	print(z)