import numpy
import re
import math
from collections import deque, defaultdict
import itertools

def main():
	"""
	テストコード実行
	:return:
	"""
	"""
	連結を隣接行列で管理 + DFS
	"""
	n, m = map(int, input().split())
	table = [[0] * n for _ in range(n)] #隣接行列
	for _ in range(m):
		a, b = map(int, input().split())
		table[a - 1][b - 1] = 1
		table[b - 1][a - 1] = 1
	cnt = 0
	for pattern in itertools.permutations(range(n)): #全ての点が繋がっている状態は順列の積で記述
		if pattern[0] != 0: #スタートがゼロ(頂点1)でなかった場合
			break
		factor = 1
		for i in range(n - 1):
			factor *= table[pattern[i]][pattern[i + 1]] #0なら頂点1から繋がっておらず、1なら頂点1から全ての点へ繋がっている
		cnt += factor #頂点1から繋がっていれば加算

	print(cnt)

if __name__ == '__main__':
	main()
