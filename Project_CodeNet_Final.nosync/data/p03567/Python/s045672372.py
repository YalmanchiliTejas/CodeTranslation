def slove():
    import sys
    input = sys.stdin.readline
    s = str(input().rstrip('\n'))
    for i in range(1, len(s)):
        if s[i] == "C" and s[i-1] == "A":
            print("Yes")
            exit()
    print("No")


if __name__ == '__main__':
    slove()
