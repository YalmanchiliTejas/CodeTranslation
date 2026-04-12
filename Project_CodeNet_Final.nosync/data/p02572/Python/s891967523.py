def findProductSum(A, n): 
      
    # calculating array sum (a1 + a2 ... + an) 
    array_sum = 0
    for i in range(0, n, 1): 
        array_sum += A[i]
  
    # calcualting square of array sum 
    # (a1 + a2 + ... + an)^2 
    array_sum_square = (array_sum * array_sum )
  
    # calcualting a1^2 + a2^2 + ... + an^2 
    individual_square_sum = 0
    for i in range(0, n, 1): 
        individual_square_sum += (A[i] * A[i]) 
  
    # required sum is (array_sum_square - 
    # individual_square_sum) / 2 
    return (array_sum_square - individual_square_sum) // 2 
n = int(input())
a = [int(x) for x in input().split()]
MOD = 10**9 +7

print(int(findProductSum(a,n))%MOD)

# print(s%MOD)