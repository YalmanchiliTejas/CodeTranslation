N, X = map(int, input().split())
A = [1] * 55
memo = {}


def func(n, x):
    if x <= 0:
        return 0
    if n == 0:
        return 1
    if (n, x) in memo:
        return memo[(n, x)]

    if x == 1:
        return 0
    if 1 < x <= 1 + A[n-1]:
        memo[(n, x)] = func(n-1, x-1)
        return memo[(n, x)]
    if x == 2 + A[n-1]:
        memo[(n, x)] = func(n-1, x-1) + 1
        return memo[(n, x)]
    if 2 + A[n-1] < x < A[n]:
        memo[(n, x)] = func(n-1, A[n-1]) + func(n-1, x-A[n-1]-2) + 1
        return memo[(n, x)]
    else:
        memo[(n, x)] = 2 * func(n-1, A[n-1]) + 1
        return memo[(n, x)]


def main():
    for i in range(1, N+1):
        A[i] = 2 * A[i-1] + 3

    print(func(N, X))


if __name__ == '__main__':
    main()
