def findProductSum(A, n): 
      
    array_sum = sum(A)
    array_sum_square = array_sum ** 2
    
    individual_square_sum = 0
    for i in range(n): 
        individual_square_sum += A[i] * A[i] 
  
    return (array_sum_square - individual_square_sum) // 2

N = int(input())
A = list(map(int, input().split()))

print(findProductSum(A, N)%(10**9+7))
