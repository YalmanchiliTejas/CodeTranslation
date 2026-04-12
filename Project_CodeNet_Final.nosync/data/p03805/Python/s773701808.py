mat = [[] for i in range(10)]
vis  = [False for i in range(10)]
def dfs(a, n):
	all_vis= True
	for i in range(0, n):
		if vis[i]==False:
			all_vis=False
	if all_vis==True:
		return 1
	ans =0
	for i in mat[a]:
		if vis[i]==True:
			continue
		vis[i]=True
		ans = ans+dfs(i,n)
		vis[i]=False
	return ans
n , m = map(int , input().split())
for i in range(m):
	a, b= map(int ,input().split())
	a =a-1
	b=b-1
	mat[a].append(b)
	mat[b].append(a)
vis[0]=True
print(dfs(0, n))