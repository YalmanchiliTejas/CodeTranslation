import sys,math
from collections import deque,defaultdict
import operator as op
from functools import reduce

sys.setrecursionlimit(10**6) 

I=sys.stdin.readline

 #s="abcdefghijklmnopqrstuvwxyz"

"""
x_move=[-1,0,1,0,-1,1,1,-1]
y_move=[0,1,0,-1,1,1,-1,-1]
"""
def ii():
	return int(I().strip())
def li():
	return list(map(int,I().strip().split()))
def mi():
	return map(int,I().strip().split())

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x




	
def main():
	n=ii()
	arr=sorted(li())
	ss=[arr[-1]]
	for i in range(n-2,-1,-1):
		ss.append(ss[-1]+arr[i])
	ss.reverse()
	ans=0
	for i in range(n-1):
		ans+=arr[i]*ss[i+1]
	print(ans%(10**9+7))
			


	

























	
	
	





if __name__ == '__main__':
	main()