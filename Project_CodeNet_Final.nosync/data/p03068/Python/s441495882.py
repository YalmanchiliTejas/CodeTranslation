N=int(input())
S=input()
K=int(input())

x=S[K-1]
for i in range(N):
	if S[i]!=x:
		S_list=list(S)
		S_list[i]='*'
		S="".join(S_list)
print(S)