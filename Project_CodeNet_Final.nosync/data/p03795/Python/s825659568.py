def slove():
    import sys
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    print(n * 800 - n // 15 * 200)


if __name__ == '__main__':
    slove()
