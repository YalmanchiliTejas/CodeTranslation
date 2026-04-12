N=int(input())
S=input()
K=int(input())
ast=S[K-1]
ans=[]
for c in S:
	if c==ast:
		ans.append(c)
	else:
		ans.append("*")
print("".join(ans))