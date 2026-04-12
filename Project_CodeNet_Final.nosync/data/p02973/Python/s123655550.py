import sys

read = sys.stdin.buffer.read
input = sys.stdin.buffer.readline
inputs = sys.stdin.buffer.readlines


# mod=10**9+7
# rstrip().decode('utf-8')
# map(int,input().split())
#import numpy as np

import bisect
from collections import deque


def main():
	n=int(input())
	A=[int(input()) for _ in range(n)]
	
	Q=deque([A[0]])
	
	for i in range(1,n):
		if A[i]<=Q[0]:
			Q.appendleft(A[i])

		else:
			ix=bisect.bisect_left(Q,A[i])
			Q[ix-1]=A[i]
	
	print(len(Q))
	
	
	
	
	



if __name__ == "__main__":
	main()
