N, M = map(int, input().split())
grp = []
for i in range(0, N):
	grp.append([])
for i in range(0, M):
	A, B = map(lambda v: int(v)-1, input().split())
	grp[A].append(B)
	grp[B].append(A)
memo = []
for i in range(0, N):
	memo.append(True)
memo[0] = False
cnt = 0
stack = [[0, memo]]
while stack != []:
	now = stack.pop(-1)
	if True not in now[1]:
		cnt += 1
	else:
		for i in range(0, len(grp[now[0]])):
			next = grp[now[0]][i]
			if now[1][next]:
				nextmemo = now[1][:next] + [False]
				if next != N-1:
					nextmemo = nextmemo + now[1][next+1:]
				stack.append([next, nextmemo])
print(cnt)