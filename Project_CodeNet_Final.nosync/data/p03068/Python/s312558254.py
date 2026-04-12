N=int(input())
S=input()
K=int(input())
for a in S:
	print(a
		if a == S[K-1]
		else"*"
		,end=""
	)