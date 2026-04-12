def main():
	A, B, C, X, Y = map(int, input().split())
	max_num_c = max(X, Y)*2

	ans = A*X+B*Y
	for num_c in range(0, max_num_c+1, 2):
		num_a = max(0, X-num_c//2)
		num_b = max(0, Y-num_c//2)
		current = A*num_a+B*num_b+C*num_c
		ans = min(ans, current)

	print(ans)

if __name__ == '__main__':
    main()