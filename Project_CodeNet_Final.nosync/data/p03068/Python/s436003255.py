# -*- coding: utf-8 -*-
import sys
import math
from bisect import bisect_left
from bisect import bisect_right
import collections
input = sys.stdin.readline

# bisect_left(lists, 3)
# bisect_right(lists, 3)

def main():
	N = int(input())
	S = input()
	K = int(input())

	S=S[:-1]
	
	tmp = S[K-1]

	ans = ""
	for i in S:
		if i == tmp:
			ans += i
		else:
			ans += "*"

	print(ans)

	
	
if __name__ == "__main__":
	main()
	