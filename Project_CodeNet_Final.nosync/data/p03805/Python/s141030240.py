N, M = map(int, input().split())
grp = []
for i in range(0, N):
	lst = []
	for j in range(0, N):
		lst.append(False)
	grp.append(lst)
for i in range(0, M):
	a, b = map(int, input().split())
	grp[a-1][b-1] = True
	grp[b-1][a-1] = True
memo = [False]
goal = [False]
for i in range(1, N):
	memo.append(True)
	goal.append(False)
queue = [[0, memo]]
cnt = 0
while queue != []:
	now = queue.pop(0)
	if now[1] == goal: cnt += 1
	else:
		for i in range(0, N):
			if grp[now[0]][i] and now[1][i]:
				newmemo = []
				for j in range(0, N):
					if i == j: newmemo.append(False)
					else: newmemo.append(now[1][j])
				queue.append([i, newmemo])
print(cnt)