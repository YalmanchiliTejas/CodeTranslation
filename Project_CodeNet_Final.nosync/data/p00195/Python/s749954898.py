if __name__ == '__main__':

	A = ["A","B","C","D","E"]

	while True:
		try:
			n,m = map(int,input().split())
			max_num = n + m
			number = 0

			if n == 0 and m == 0:
				break

			for i in range(4):
				n,m = map(int,input().split())

				if max_num < n + m:
					max_num = n + m
					number = i + 1
			
			print(A[number],max_num)

		except EOFError:
			break

