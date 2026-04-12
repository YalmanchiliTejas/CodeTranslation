import sys,math
from collections import deque,defaultdict
import operator as op
from functools import reduce

I=sys.stdin.readline

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


def main():
	n=ii()
	if n>=30:
		print("Yes")
	else:
		print("No")





		










		


		










		






if __name__ == '__main__':
	main()