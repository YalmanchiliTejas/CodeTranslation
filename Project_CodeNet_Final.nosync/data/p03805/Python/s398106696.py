import itertools

n,m = map(int,input().split())

ab = []
ans = 0
for _ in range(m):
	ab.append(list(map(int,input().split())))

l = list(itertools.permutations(range(1,n+1)))

for i in range(len(l)):
	count = 0
	for j in range(len(l[i])-1):
		tmp = [l[i][j],l[i][j+1]]
		if j == 0:
			if tmp[0] != 1:
				break
		tmp.sort()
		if tmp not in ab:
			break
		count += 1
		if count == n-1:
			ans += 1

print(ans)
