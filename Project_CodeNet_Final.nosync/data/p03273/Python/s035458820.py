import numpy as np
N,M=map(int,input().split())
x=[]
for n in range(N):
	x.append(list(input()))

for __ in range(2):
	check=[]
	count=0
	for _ in range(len(x[0])):
		check.append(".")
	for xi in x:
		if xi == check:
			count+=1
	for _ in range(count):
		x.remove(check)
	x=np.array(x).T.tolist()

for i in range(len(x)):
	for j in range(len(x[0])):
		print(x[i][j],end="")
	if i != len(x)-1:
		print()