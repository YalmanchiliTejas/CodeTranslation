def solve(string):
    _, *a = map(int, string.split())
    return str((sum(a)**2 - sum(map(lambda x: x**2, a))) // 2 % (10**9 + 7))


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
