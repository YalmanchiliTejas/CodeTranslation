#Python Competetive Programming Template

from sys import stdin, stdout
from math import *

testing = True

def tp(s=""):
	if testing:
		print(s)

def main():
	n, x, m = [int(i) for i in stdin.readline().split()]
	d = dict()
	a = x
	total = 0
	count = 0
	for i in range(n):
		#print("a:", a)
		count += 1
		total += a
		if a in d:
			break
		d[a] = (count, total)
		a = (a**2)%m
	else:
		print(total)
	if count != n:
		#print(d)
		looplength = count - d[a][0]
		#print("looplength:", looplength)
		loopsize = total - d[a][1]
		#print("loopsize:", loopsize)
		loopstodo = (n-count)//looplength
		total += loopstodo * loopsize
		count += loopstodo * looplength
		while count < n:
			a = (a**2)%m
			#print("a:", a)
			count += 1
			total += a
		#print(count)
		print(total)

main()