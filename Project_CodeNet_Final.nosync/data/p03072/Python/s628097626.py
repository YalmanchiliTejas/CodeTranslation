import math
import os
import random
import re
import sys
from collections import defaultdict

# sys.stdin = open('input.in', 'r')
# sys.stdout = open('output.out', 'w') 

def count(n, h):
	count = 0
	if len(h) < 1:
		return count
	max = h[0]
	for i in h:
		if i >= max:
			max = i 
			count += 1

	return count

if __name__ == '__main__':
	n = int(input())
	h = list(map(int, input().rstrip().split()))
	print(count(n, h))