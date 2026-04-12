def slove():
    import sys
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    s = str(input().rstrip('\n'))
    k = int(input().rstrip('\n'))
    ls = []
    for i in range(n):
        if s[i] != s[k-1]:
            ls.append("*")
        else:
            ls.append(s[i])
    print("".join(ls))


if __name__ == '__main__':
    slove()
