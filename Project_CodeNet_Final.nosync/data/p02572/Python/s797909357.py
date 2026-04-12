n=int(input())
a=list(map(int,input().split()))
MOD=10**9+7
def findProductSum(A, n): 
    array_sum = 0
    for i in range(0, n, 1): 
        array_sum=array_sum+A[i]
    array_sum_square = array_sum * array_sum 
    individual_square_sum = 0
    for i in range(n): 
        individual_square_sum += A[i] * A[i]
    return (array_sum_square - individual_square_sum)//2

print(findProductSum(a,n)%MOD)