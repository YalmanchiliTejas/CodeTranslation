def count_b(n):
    return 2 ** (n + 2) - 3

def count_p(n):
    return 2 ** (n + 1) - 1

def solve(n, x):
    if x <= 0:
        return 0
    if n == 0:
        return 1
    b = count_b(n-1)
    if x < (b + 1):
        return solve(n-1, x-1)
    return count_p(n-1) + (1 if x >= (b + 2) else 0) + solve(n-1, x-b-2)

def main():
    n, x = list(map(int, input().split()))
    print(solve(n, x))

if __name__ == "__main__":
    main()
