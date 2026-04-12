import itertools
n,m = map(int,input().split())
perm = []
for j in range(n):
	perm.append(j)
perm_list = list(itertools.permutations(perm))
	
net_arr = [[0 for _ in range(n)] for _ in range(n)]
for i in range(0,m):
	a,b = map(int,input().split())
	a -= 1
	b -= 1
	net_arr[a][b] = 1
	net_arr[b][a] = 1
def check_path(path,net):
	for i in range(len(path)-1):
		if not net_arr[path[i]][path[i+1]] == 1:
			return False
	return True
	
ans = 0
for path in perm_list:
	if not path[0] == 0:
		break
	if check_path(path,net_arr):
		ans += 1	
print(ans)
