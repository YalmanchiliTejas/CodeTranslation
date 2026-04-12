n = int(input())
A = list(map(int, input().split()))
array_sum_square = sum(A)**2
individual_square_sum = 0
for i in range(0, n, 1):
    individual_square_sum += A[i]**2
print((array_sum_square - individual_square_sum) // 2 % (7 + 10 ** 9))
