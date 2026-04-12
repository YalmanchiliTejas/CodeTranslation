import numpy as np
def niku(level, num):
	maisu = 2**(level+2)-3
	if(num <= level):
		return 0
	elif(level == 0):
		return 1
	elif(num < (maisu+1)/2):
		return niku(level-1, num-1)
	elif(num == (maisu+1)/2):
		return 2**(level+1-1)-1+1
	else:
		return 2**(level+1-1)-1+1+niku(level-1, num-((maisu+1)/2))

def main():
	
	buf = input().split()
	n = int(buf[0])
	x = int(buf[1])
	print(niku(n, x))
		
main()