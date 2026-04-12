def slove():
    import sys
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    s = list(str(input().rstrip('\n')))
    k = int(input().rstrip('\n'))
    ts = s[k-1]
    for i in range(n):
        if s[i] != ts:
            s[i] = "*"
    print("".join(s))


if __name__ == '__main__':
    slove()
