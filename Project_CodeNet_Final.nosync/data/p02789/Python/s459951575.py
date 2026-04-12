def solve(n, m):
    return "Yes" if n == m else "No"

n, m = map(int, input().split())
print(solve(n, m))