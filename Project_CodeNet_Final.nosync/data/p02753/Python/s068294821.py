def solve(string):
    return "No" if string in ["AAA", "BBB"] else "Yes"


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
