def slove():
    import sys
    input = sys.stdin.readline
    x, y, z = list(map(int, input().rstrip('\n').split()))
    x -= z
    print(x // (y + z))


if __name__ == '__main__':
    slove()
