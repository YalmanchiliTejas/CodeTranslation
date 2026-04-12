H,W = map(int,input().split())
A=[""]*H
for i in range (H):
	A[i]=input()

V=[0]*H
X=[0]*W
for i in range (H):
	for j in range (W):
		if A[i][j]=="#":
			V[i]=1
			X[j]=1

for i in range (H):
	if V[i]==1:
		for j in range (W):
			if X[j]==1:
				print(A[i][j],end="")
		print()