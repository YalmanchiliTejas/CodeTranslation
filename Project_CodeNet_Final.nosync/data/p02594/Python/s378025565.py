import math
# import bisect
import sys
# from collections import Counter
input = sys.stdin.readline
def inp():
	return(int(input()))
def inlt():
	return(list(map(int,input().split())))
def insr():
	s = input()
	return(s[:len(s)-1])
def invr():
	return(map(int,input().split()))
def print_fract(p,q):
	g = math.gcd(p,q)
	p//=g
	q//=g
	print(str(p)+"/"+str(q))
# list1, list2 = zip(*sorted(zip(list1, list2)))
X = inp()
if X >= 30:
	print("Yes")
else:
	print("No")