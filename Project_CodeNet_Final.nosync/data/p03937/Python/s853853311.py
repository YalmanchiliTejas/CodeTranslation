def slove():
    import sys
    input = sys.stdin.readline
    h, w = list(map(int, input().rstrip('\n').split()))
    cnt = 0
    for i in range(h):
        cnt += str(input().rstrip('\n')).count("#")
    print("Possible" if cnt == (h + w - 1) else "Impossible")


if __name__ == '__main__':
    slove()
