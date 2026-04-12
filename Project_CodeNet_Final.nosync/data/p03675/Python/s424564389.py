def slove():
    import sys
    import collections
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    a = list(map(int, input().rstrip('\n').split()))
    ls = collections.deque()
    for i, v in enumerate(a):
        if i % 2 == n % 2:
            ls.append(v)
        else:
            ls.appendleft(v)
    print(*ls)


if __name__ == '__main__':
    slove()
