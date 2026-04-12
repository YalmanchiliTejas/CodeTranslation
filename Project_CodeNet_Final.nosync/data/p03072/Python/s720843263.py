def main():
	N = int(input())
	Hi = list(map(int, input().split()))
	current_max = 0
	ans = 0
	for h in Hi:
		if h >= current_max:
			ans += 1
			current_max = h
	print(ans)


if __name__ == '__main__':
    main()