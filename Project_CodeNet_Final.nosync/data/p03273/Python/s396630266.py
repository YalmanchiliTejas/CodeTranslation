h,w = map(int,raw_input().split())

arr = [raw_input() for i in range(h)]

ans = []
for i in range(h):
	count = 0
	for j in range(w):
		if arr[i][j] == '.':
			count += 1

	if count != w:
		ans.append(arr[i]) 


ret = [[] for i in range(len(ans))]
for i in range(w):
	count = 0
	for j in range(len(ans)):
		if ans[j][i] == '.':
			count += 1

	if count != len(ans):
		for j in range(len(ans)):
			ret[j].append(ans[j][i])

for i in ret:
	print ''.join(i)

