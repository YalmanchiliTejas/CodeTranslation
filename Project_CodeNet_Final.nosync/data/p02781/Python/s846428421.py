import sys

read = sys.stdin.buffer.read
input = sys.stdin.buffer.readline
inputs = sys.stdin.buffer.readlines

# mod=10**9+7
# rstrip().decode('utf-8')
# map(int,input().split())
# import numpy as np
from functools import lru_cache

def main():
	n=int(input())
	k=int(input())
	
	@lru_cache(None)
	def f(n,k):
		if n<10:
			if k==0:
				return 1
			if k==1:
				return n
			return 0
		q, r = divmod(n, 10)
		ret = 0
		if k>=1:
			ret+=f(q,k-1)*r
			ret+=f(q-1,k-1)*(9-r)
		ret+=f(q,k)
		return ret
	print(f(n,k))
	
if __name__ == "__main__":
	main()
