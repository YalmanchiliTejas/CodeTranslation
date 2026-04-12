# import sys; input = sys.stdin.buffer.readline
# sys.setrecursionlimit(10**7)
from collections import defaultdict
con = 10 ** 9 + 7; INF = float("inf")

def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N = int(input())
	A = getlist()
	S = sum(A)
	S %= con
	ans = 0
	for i in range(N):
		ans += A[i] * (S - A[i])
		ans %= con

	ans = ans * pow(2, con - 2, con)
	ans %= con
	print(ans)

if __name__ == '__main__':
	main()