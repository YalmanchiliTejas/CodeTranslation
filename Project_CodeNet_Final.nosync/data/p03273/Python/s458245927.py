A=[]
h,w=map(int,input().split())
for i in range(h):
	s=input()
	if s.count("#")!=0:
		A.append(s)
B=[]
C=[]
for i in range(w):
	cnt=0
	for j in range(len(A)):
		if A[j][i]==".":
			cnt+=1
	if cnt==len(A):
		B.append(i)
for i in range(w):
	c=""
	for j in range(len(A)):
		if i not in B:
			c+=A[j][i]
	if len(c)>0:
		C.append(c)
for j in range(len(C[0])):
	p=""
	for i in range(len(C)):
		p+=C[i][j]
	print(p)
