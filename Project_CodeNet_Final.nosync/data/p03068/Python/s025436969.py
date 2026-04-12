N=int(input())
S=input()
K=int(input())

T=[]
for i in range(len(S)):
	if S[K-1]!=S[i]:
		T.append('*')
	else:
		T.append(S[i])
print(''.join(T))