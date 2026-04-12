import sys
import bisect

def input():
    return sys.stdin.readline().rstrip()

def LIS(seq):
	l = [seq[0]]
	for i in range(1,len(seq)):
	    if seq[i] >= l[-1]:
	        l.append(seq[i])
	    else:
	        l[bisect.bisect_right(l, seq[i])] = seq[i]

	return(len(l))

def main():
	n=int(input())
	a=[int(input()) for _ in range(n)]
	print(LIS(a[::-1]))

main()