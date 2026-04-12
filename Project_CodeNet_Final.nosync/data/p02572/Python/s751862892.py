# Efficient python 3 program to find sum 
# pair products in an array. 
mod=1000000007
# required function 
def findProductSum(A, n): 
	
	# calculating array sum (a1 + a2 ... + an) 
	array_sum = 0
	for i in range(0, n, 1): 
		array_sum = array_sum + A[i] 

	# calcualting square of array sum 
	# (a1 + a2 + ... + an)^2 
	array_sum_square = array_sum * array_sum 

	# calcualting a1^2 + a2^2 + ... + an^2 
	individual_square_sum = 0
	for i in range(0, n, 1): 
		individual_square_sum += A[i] * A[i] 

	# required sum is (array_sum_square - 
	# individual_square_sum) / 2 
	return (array_sum_square -
			individual_square_sum) // 2

# Driver code 
if __name__ == '__main__': 
    n=int(input())
    a=input().split()
    for i in range(n):
        a[i]=int(a[i])
    ans=int(findProductSum(a,n))
    ans%=mod
    print(ans)