if __name__ == '__main__':
	N = int(input())
	H = list(map(int, input().split()))

	max_height = 0
	ans = 0
	for i in H:
		if i >= max_height : 
			max_height = i
			ans += 1

	print(ans)