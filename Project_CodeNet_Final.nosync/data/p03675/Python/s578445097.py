def slove():
    import sys
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    a = list(map(int, input().rstrip('\n').split()))
    ls = []
    for i in range(n-1, -1, -2):
        ls.append(a[i])
    for i in range(0 if n % 2 == 0 else 1, n, 2):
        ls.append(a[i])
    print(*ls)


if __name__ == '__main__':
    slove()
