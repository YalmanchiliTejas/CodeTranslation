#ABC054C
import copy
N,M=map(int,input().split())
C={}
for m in range(M):
	a,b=list(map(int,input().split()))
	C[b]=C.get(b,[])+[a]
	C[a]=C.get(a,[])+[b]
def Search(a,check):
	ans=0
	if all(check):
		return 1
	else:
		check[a-1]=1
		for b in C[a]:
			tmp=copy.deepcopy(check)
			if check[b-1]!=1:
				tmp[b-1]=1
				ans+=Search(b,tmp)
		return ans
print(Search(1,[0]*N))
