MODULO = 1_000_000_007


def main():
    N = int(input())
    A = [int(_x) for _x in input().split()]
    sums = [0]*N
    for i in reversed(range(N)):
        if (i == N-1):
            sums[i] = A[i]
        else:
            sums[i] = sums[i+1] + A[i]

    result = 0
    for i in range(N):
        if i == N-1:
            break
        result = (result + A[i] * sums[i+1]) % MODULO
    print(result)


main()
