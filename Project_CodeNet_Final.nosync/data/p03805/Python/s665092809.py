def saiki(arr_lst,count,path,N):
	if len(path) == N:
		count[0] += 1
	else:
		here = path[-1]
		arrival = arr_lst[here]
		for next in arrival:
			if not next in path:
				newpath = path[:]
				newpath.append(next)
				saiki(arr_lst,count,newpath,N)


if __name__ == '__main__':
	N, M = map(int, input().split())
	arr_lst = [[]]

	for i in range(1,N+1):
		arr_lst.append([])

	for _ in range(M):
		a, b = map(int, input().split())
		arr_lst[a].append(b)
		arr_lst[b].append(a)

	count = [0]

	saiki(arr_lst,count,[1],N)

	print(count[0])