
def findProductSum(A, n):

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


    return (array_sum_square - individual_square_sum) // 2


def main():
    n = int(input())
    A = [int(x) for x in input().split()]
    # n = len(A)
    mod = (10**9) + 7
    print(int(findProductSum(A, n))%mod)

main()

