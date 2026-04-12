# -*- coding:utf-8 -*-
#ICPC得点集計ソフトウェア
import sys
def solve(n):
	nums = []
	for i in xrange(n):
		temp = input()
		nums.append(temp)
	nums.sort()
	sum = 0
	for i in xrange(1,n-1):
		sum += nums[i]
	return sum / (n-2)


if __name__ == "__main__":
	while 1:
		N = input()
		if N == 0:
			sys.exit()
		else:
			print solve(N)