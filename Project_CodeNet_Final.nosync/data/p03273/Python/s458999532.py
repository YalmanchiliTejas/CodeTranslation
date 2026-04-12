H,W=map(int,input().split())
A=[]
for i in range(H):
	A.append(input())

while "."*W in A:
	A.remove("."*W)

H=len(A)
B=[[] for _ in range(H)]
X=[[] for i in range(W)]

for i in range(W):
	for j in range(H):
		X[i].append(A[j][i])

while ["." for p in range(H)] in X:
	X.remove(["." for c in range(H)])

W=len(X)
for i in range(H):
	for j in range(W):
		B[i].append(X[j][i])

for i in range(H):
  print("".join(B[i]))
  