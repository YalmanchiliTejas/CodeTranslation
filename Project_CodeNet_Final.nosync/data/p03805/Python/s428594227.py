def check_path(dots_list,dot,golist):
	List = dots_list[:]
	List.remove(dot)

	c = 0

	if len(List) > 0:
		for i in golist[dot-1]:
			if List.count(i) > 0:
				c += check_path(List, i, golist)
			else:
				c += 0
	else:
		c = 1

	return c



if __name__ == '__main__':

	#入力
	N, M = map(int, input().split())
	ms = []
	for i in range(0,M):
		a, b = map(int, input().split())
		ms.append([a, b])

	golist = []
	dots_list = []

	#各頂点の隣接点をリストに
	for i in range(1,N+1):
		golist_each = []
		dots_list.append(i)
		for j in range(0,M):
			if ms[j][0] == i:
				golist_each.append(ms[j][1])
			elif ms[j][1] == i:
				golist_each.append(ms[j][0])

		golist.append(golist_each)

	ans = check_path(dots_list, 1, golist)
	print(ans)