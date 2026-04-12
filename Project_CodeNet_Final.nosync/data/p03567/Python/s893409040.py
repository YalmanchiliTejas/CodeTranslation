def slove():
    import sys
    input = sys.stdin.readline
    s = str(input().rstrip('\n'))
    print("Yes" if len(s) != len(s.replace("AC", "")) else "No")


if __name__ == '__main__':
    slove()
