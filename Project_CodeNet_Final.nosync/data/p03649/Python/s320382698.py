import sys; input = sys.stdin.buffer.readline
from collections import defaultdict
con = 10 ** 9 + 7; INF = float("inf")

def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N = int(input())
	A = sorted(getlist())
	cnt = 0

	while True:
		if A[-1] <= N - 1:
			print(cnt)
			return
		if (A[-1] - (N - 1)) % N == 0:
			K = int((A[-1] - (N - 1)) // N)
		else:
			K = int((A[-1] - (N - 1)) // N) + 1
		
		#処理
		cnt += K
		A[-1] -= K * N
		for i in range(N - 1):
			A[i] += K
		A = sorted(A)

	print(cnt)


if __name__ == '__main__':
	main()