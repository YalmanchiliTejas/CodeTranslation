def solve(string):
    n, m = map(int, string.split())
    return "Yes" if n == m else "No"


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
