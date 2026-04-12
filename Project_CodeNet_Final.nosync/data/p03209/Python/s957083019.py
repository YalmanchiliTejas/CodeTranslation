N, X = [int(_) for _ in input().split()]

def solve(n, x):

    if n == 0:
        return 1

    left = 1
    if x == left:
        return 0

    right = 2 ** (n + 2) - 3
    pivot = right // 2 + 1

    if x == right:
        return 1 + 2 * solve(n - 1, pivot - 2)

    if x < pivot:
        return solve(n - 1, x - 1)

    elif x == pivot:
        return 1 + solve(n - 1, pivot - 2)

    else:
        return solve(n - 1, pivot - 2) + 1 + solve(n - 1, x - pivot)




print(solve(N, X))