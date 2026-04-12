import itertools
n,m = map(int,raw_input().split())

permutations = list(itertools.permutations(range(1,n)))


arr = [[-1 for i in range(n)] for j in range(n)]


for i in range(m):
	f,t = map(int,raw_input().split())
	f -= 1
	t -= 1
	arr[f][t] = 1
	arr[t][f] = 1


ans = 0
for p in permutations :
	count = 0
	if arr[0][p[0]] == 1 :
		count += 1
	else:
		next

	for i in range(0,len(p)-1):
		if arr[p[i]][p[i+1]] == 1 :
			count += 1

		else:
			break

	if count == n-1 :
		ans += 1
print ans