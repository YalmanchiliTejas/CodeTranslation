import sys; input = sys.stdin.buffer.readline
sys.setrecursionlimit(10**7)
from collections import defaultdict
con = 10 ** 9 + 7; INF = float("inf")

def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	X = int(input())
	if X >= 30:
		print("Yes")
	else:
		print("No")




if __name__ == '__main__':
	main()