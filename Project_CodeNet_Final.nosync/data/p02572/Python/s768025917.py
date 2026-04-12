import math
import sys,collections
from sys import stdin, stdout  
#MAXN = 10000001

def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip() 
def input(): return sys.stdin.readline().strip()
#spf = [0 for i in range(MAXN)] 
def file():
	sys.stdin = open('input.py', 'r')
	sys.stdout = open('output.py', 'w') 
def is_subsequence(x, y):
    """Test whether x is a subsequence of y"""
    x = list(x)
    for letter in y:
        if x and x[0] == letter:
            x.pop(0)

    return not x    
def sieve(): 
	spf[1] = 1
	for i in range(2, MAXN): 
		spf[i] = i 
	for i in range(4, MAXN, 2): 
		spf[i] = 2

	for i in range(3, mt.ceil(mt.sqrt(MAXN))): 
		if (spf[i] == i): 
			for j in range(i * i, MAXN, i): 
				if (spf[j] == j): 
					spf[j] = i 
def getFactorization(x): 
	ret = list() 
	while (x != 1): 
		ret.append(spf[x]) 
		x = x // spf[x] 

	return ret 
def getFloor(A, x):

    (left, right) = (0, len(A) - 1)

    ind,floor = -1,-1
    while left <= right:
        mid = (left + right) // 2
        '''if A[mid] == x:
            return mid'''
        if x < A[mid]:
            right = mid - 1
        else:
            floor = A[mid]
            ind=mid
            left = mid + 1
            
    return ind
def check(st) : 
  
    # Compute sum of digits 
    n = len(st) 
    digitSum = 0
      
    for i in range(0,n) : 
        digitSum = digitSum + (int)(st[i]) 
  
    # Check if sum of digits 
    # is divisible by 9. 
    return (digitSum % 9 == 0)     
def isPowerOfTwo(n): 
    if (n == 0): 
        return False
    while (n != 1): 
            if (n % 2 != 0): 
                return False
            n = n // 2
            
              
    return True
def kitte(n):
	c=0
	while(n!=0):
		n=n//2
		c+=1
	return c	
def aa(b,c):
	m=min(b,c)
	b-=m
	c-=m
	if(c>0 and b>0):
		return(m+((b+c)//3))
	else:
		return(m)
def bb(a,c):
	m=min(a,c)
	a-=m
	c-=m
	if(c>0 and a>0):
		return(m+((a+c)//3))
	else:
		return(m)
def cc(b,a):
	m=min(b,a)
	b-=m
	a-=m
	if(a>0 and b>0):
		return(m+((b+a)//3))
	else:
		return(m)		
def findProductSum(A, n): 
      
    # calculating array sum (a1 + a2 ... + an) 
    array_sum = 0
    for i in range(0, n, 1): 
        array_sum = (array_sum + A[i])
  
    # calcualting square of array sum 
    # (a1 + a2 + ... + an)^2 
    array_sum_square = (array_sum * array_sum)
  
    # calcualting a1^2 + a2^2 + ... + an^2 
    individual_square_sum = 0
    for i in range(0, n, 1): 
        individual_square_sum += (A[i] * A[i])
  
    # required sum is (array_sum_square - 
    # individual_square_sum) / 2 
    return (array_sum_square - 
            individual_square_sum) // 2		
#file()
#sieve() 
mod=(10**9)+7	
def main():
		n=int(input())
		l=get_array()
		s=0
		s=findProductSum(l,n)
		print(s%mod)		

	



	

	
			


		




		






		







			



	

	




	





















	




















		
			


		

			

		





			

	























				

	















	

	










if __name__ == '__main__':
    main()
