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
	H = input().split(" ")
	H = [int(s) for s in H]
	

		



 
	ans = 0
	max = 0
	for i, val in enumerate(H):
		if i == 0:
			ans += 1
			max = val
			continue
		if max <= val:
			max = val
			ans += 1
			
 
	print(ans)

	
	
if __name__ == "__main__":
	main()
	