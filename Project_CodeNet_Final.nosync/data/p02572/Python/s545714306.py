M=1000000007
def findProductSum(A, n): 
    s = 0
    for i in range(n): 
        s+=A[i] 
    array_sum_square = s*s
    individual_square_sum = 0
    for i in range(n): 
        individual_square_sum += A[i]*A[i]
    return (array_sum_square -individual_square_sum) // 2
n=int(input())
a=list(map(int,input().split()))
print(findProductSum(a,n)%M)