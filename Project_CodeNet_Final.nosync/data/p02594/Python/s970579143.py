import sys,math,collections
from collections import defaultdict

#from itertools import permutations,combinations
	
def file():
	sys.stdin = open('input.py', 'r')
	sys.stdout = open('output.py', 'w') 
def get_array():
	l=list(map(int, input().split()))
	return l
def get_2_ints():	
	a,b=map(int, input().split())
	return a,b
def get_3_ints():	
	a,b,c=map(int, input().split())
	return a,b,c	
def sod(n):
	n,c=str(n),0
	for i in n:	
		c+=int(i)
	return c	
def isPrime(n):
    if (n <= 1):
        return False
    if (n <= 3):
        return True
    if (n % 2 == 0 or n % 3 == 0):
        return False
    i = 5
    while(i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6
  
    return True
def getFloor(A, x):

	(left, right) = (0, len(A) - 1)

	floor = -1
	while left <= right:
		mid = (left + right) // 2
		if A[mid] == x:
			return A[mid]
		elif x < A[mid]:
			right = mid - 1
		else:
			floor = A[mid]
			left = mid + 1
			
	return floor
def floorSqrt(x) : 
  
    # Base cases 
    if (x == 0 or x == 1) : 
        return x 
   
    # Do Binary Search for floor(sqrt(x)) 
    start = 1
    end = x    
    while (start <= end) : 
        mid = (start + end) // 2
          
        # If x is a perfect square 
        if (mid*mid == x) : 
            return mid 
              
        # Since we need floor, we update  
        # answer when mid*mid is smaller 
        # than x, and move closer to sqrt(x) 
        if (mid * mid < x) : 
            start = mid + 1
            ans = mid 
              
        else : 
              
            # If mid*mid is greater than x 
            end = mid-1
              
    return ans	
#file()
def main():
	
		n=int(input())
		
		if(n>=30):
			print("Yes")
		else:
			print("No")	



	

	
	

		











		
		

		























































				

			







            
			
































		








if __name__ == '__main__':
    main()