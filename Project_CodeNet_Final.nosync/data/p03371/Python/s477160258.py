# -*- coding: utf-8 -*-
import sys
import copy
import collections
from bisect import bisect_left
from bisect import bisect_right
from collections import defaultdict
from heapq import heappop, heappush
import numpy as np
import statistics
from statistics import mean, median,variance,stdev
import math

def main():
	A,B,C,X,Y = map(int, input().split(" "))
	
	if C >= A and C >= B:
		
		print(A*X + B*Y)
		sys.exit()
	
	base = A*X + B*Y
	
	if X == Y:
		tmp = C * 2 * Y
		
		print(min(base, tmp))
		sys.exit()
	

	part1 = A*X
	part21 = C*2*Y
	part22 = B*Y
	tmp = min(part21,part22)
	tmp = part1 + tmp
	ans = min(base, tmp)
	#print(ans)
			
	part1 = C*2*X
	Y_tmp = Y-X
	if Y_tmp > 0:	
		part21 = C*2*Y_tmp
		part22 = B*Y_tmp
		tmp = min(part21,part22)
		tmp = part1 + tmp
	else:
		tmp = part1
	ans = min(ans, tmp)
	#print(ans)
	
	part1 = B*Y
	part21 = C*2*X
	part22 = A*X
	tmp = min(part21,part22)
	tmp = part1 + tmp
	ans = min(ans, tmp)
	#print(ans)
		
	part1 = C*2*Y
	X -= Y
	if X > 0:
		part21 = C*2*X
		part22 = A*X
		tmp = min(part21,part22)
		tmp = part1 + tmp
	else:
		tmp = part1
	ans = min(ans, tmp)
			
	print(ans)
	
if __name__ == "__main__":
	main()
