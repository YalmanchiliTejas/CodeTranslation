def solve(string):
    return "Yes" if int(string) >= 30 else "No"
    pass


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
