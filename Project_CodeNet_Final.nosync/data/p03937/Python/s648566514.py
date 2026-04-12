def slove():
    import sys
    input = sys.stdin.readline
    h, w = list(map(int, input().rstrip('\n').split()))
    a = [list(str(input().rstrip('\n'))) for _ in range(h)]
    cnt = 0
    for i in range(h):
        cnt += a[i].count("#")
    print("Possible" if cnt == (h + w - 1) else "Impossible")


if __name__ == '__main__':
    slove()
