N,M=map(int, input().split())
l=[list(map(int, input().split())) for _ in range(M)]
ans=[i for i in range(1,N+1)]
c=[1]


def dfs(cnt):
	if len(cnt)==N and sorted(cnt)==ans:
		return 1
	elif len(cnt)>=N:
		return 0
	temp=[]
	ret=0
	for i in range(M):
		if cnt[-1]==l[i][0]:
			temp.append(l[i][1])
		elif cnt[-1]==l[i][1]:
			temp.append(l[i][0])
	for h in temp:
		cnt.append(h)
		ret+=dfs(cnt)
		cnt.pop(-1)
	return ret

print(dfs(c))		