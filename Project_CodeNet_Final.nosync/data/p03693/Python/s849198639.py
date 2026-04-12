def slove():
    import sys
    input = sys.stdin.readline
    rgb = list(map(str, str(input().rstrip('\n')).split()))
    print("YES" if int("".join(rgb)) % 4 == 0 else "NO")


if __name__ == '__main__':
    slove()
