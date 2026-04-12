H,W=map(  int,raw_input().split() )
A=[ list(raw_input())  for i in range(H)] 

for i in range(H):
	for j in range(W):
		if A[i][j]=="#":
			break
	else:
		for j in range(W):
			A[i][j]=0


for j in range(W):
	for i in range(H):
		if A[i][j]=="#":
			break
	else:
		for i in range(H):
			A[i][j]=0



for i in range(H):
	str=""
	for j in range(W):
		if A[i][j]!=0:
			str+=A[i][j]
	if len(str)!=0:
		print str
