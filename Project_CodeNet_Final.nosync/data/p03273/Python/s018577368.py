H, W = map(int, input().split())		# 5 7

M = list( input() for _ in range(H) )
A=[]
C=[]
r=0
c=W

#print(M)

for i in range(H):
	m = M[i]
	if "#" in m:
		A.append(m)
		r+=1

#print(r,c)
#print(A)

for j in range(c):
	for i in range(r):
		a = A[i][j]
		if a=='#': break
	else:
		C.append(j)

#print(C)

for r in A:
#	print(r)
	for c in range(len(r)):
		if not (c in C):
			print(r[c], end='')
	print('')