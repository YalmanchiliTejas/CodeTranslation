def solve(string):
    x, y, z = map(int, string.split())
    return str((x - z) // (y + z))


if __name__ == '__main__':
    print(solve(input()))
