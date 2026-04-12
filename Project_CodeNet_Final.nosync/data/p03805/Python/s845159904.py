from itertools import permutations

def main():
	n, m = list(map(int, input().split()))
	adj_list = [[] for _ in range(n)]
	for i in range(m):
		u, v = list(map(int, input().split()))
		adj_list[u-1].append(v-1)
		adj_list[v-1].append(u-1)
	pts = list(permutations(list(range(1, n))))
	
	#print(pts)
	ans = 0
	for pt in pts:
		cur = 0
		for nxt in pt:
			if nxt in adj_list[cur]:
				cur = nxt
			else:
				break
		else:
			ans += 1
	print(ans)

if __name__ == '__main__':
	main()
