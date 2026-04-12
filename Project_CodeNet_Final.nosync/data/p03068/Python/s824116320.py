input()
S=input()
k=int(input())
for s in S:
	if s==S[k-1]:
		print(s,end="")
	else:
		print("*",end="")