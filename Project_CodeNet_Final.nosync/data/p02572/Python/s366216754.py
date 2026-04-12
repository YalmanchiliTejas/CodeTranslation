from sys import stdin, stdout,stderr
import time,math
from collections import defaultdict as dd
 
def pn(ob):stdout.write(str(ob))
def inp():return stdin.readline()

mod = 10**9 + 7

def main():
	n = int(inp())
	arr = list(map(int, inp().split()))

	tot = 0
	res = 0

	for x in arr:
		tot += x
		tot %= mod

	for x in arr:
		tot -= x
		res = (res + (x * tot)% mod) % mod
		res %= mod

	pn(res)
  
if __name__ == '__main__':
	main()
	
#n,m=map(int,input().split()) 
# for i in range(n):
#     t=int(stdin.readline()) # input using fast i/p method 
#     if t%m == 0:
#         stdout.write(str(t)+'\n') #input using fast o/p method
 
# take line of integers as input
# 	arr = list(map(int, inp().split()))