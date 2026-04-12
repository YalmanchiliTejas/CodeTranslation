m = 1000000000+7


def findProductSum(A, n):

    array_sum = 0
    for i in range(0, n, 1):
        array_sum = (array_sum + A[i]) % m

    array_sum_square = (array_sum * array_sum) % m

    individual_square_sum = 0
    for i in range(0, n, 1):
        individual_square_sum = (individual_square_sum + (A[i] * A[i]) % m)%m

    aaa=(array_sum_square-individual_square_sum+m)%m
    inv=pow(2,m-2,m)
    anss=aaa*inv

    return anss


n = int(input())
A = list(map(int, input().split()))

print(int(int(findProductSum(A, n)) % m))
