def findProductSum(A, n): 
    array_sum = sum(A)
    array_sum_square = array_sum ** 2
    individual_square_sum = 0
    for i in range(0, n, 1): 
        individual_square_sum += A[i] * A[i] 
    return (array_sum_square -
            individual_square_sum) // 2

n = input()
arr = list(map(int, input().split()))
res = findProductSum(arr, len(arr)) % (10**9 + 7)
print(res)


