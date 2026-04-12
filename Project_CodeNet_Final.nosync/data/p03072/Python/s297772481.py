def slove():
    import sys
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    h = list(map(int, input().rstrip('\n').split()))
    mh = 0
    cnt = 0
    for v in h:
        if v >= mh:
            cnt += 1
        mh = max(mh, v)
    print(cnt)


if __name__ == '__main__':
    slove()
