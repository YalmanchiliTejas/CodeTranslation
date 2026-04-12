def slove():
    import sys
    input = sys.stdin.readline
    d = [7, 5, 3]
    x = int(input().rstrip('\n'))
    print("YES" if x in d else "NO")


if __name__ == '__main__':
    slove()
