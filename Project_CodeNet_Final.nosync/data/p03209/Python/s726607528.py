N,K = map(int,input().split())

l = [1]*(N+2)
p = [1]*(N+2)


for i in range(N+1):
	l[i+1] = 2*l[i]+3
	p[i+1] = 2*p[i]+1

def dfs(level,dist):
	ans = 0
	if level==0:
		return 1
	elif dist==1:
		return 0
	elif dist==l[level]:
		return p[level]
	elif dist==2+l[level-1]:
		return p[level-1]+1
	else:
		if dist <= 1+l[level-1]:
			ans = dfs(level-1,dist-1)
		else:
			ans = p[level-1]+1+dfs(level-1,dist-2-l[level-1])
	return ans

print(dfs(N,K))
