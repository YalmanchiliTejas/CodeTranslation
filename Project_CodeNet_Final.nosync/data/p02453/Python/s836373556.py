import bisect

if __name__ == '__main__':

	input()
	A = list(map(int,input().split()))
	n = int(input())

	for _ in range(n):
		x = int(input())
		
		bi = bisect.bisect_left(A,x)
		print(bi)

