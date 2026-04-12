def slove():
    import sys
    import bisect
    import collections
    import fractions
    import heapq
    input = sys.stdin.readline
    h, w = list(map(int, input().rstrip('\n').split()))
    a = [list(str(input().rstrip('\n'))) for _ in range(h)]
    hl = [True] * h
    wl = [True] * w
    for i in range(h):
        if a[i].count("#") == 0:
            hl[i] = False
    for i in range(w):
        b = False
        for j in range(h):
            if a[j][i] == "#":
                b = True
                break
        if not b:
            wl[i] = False
    for i in range(h):
        if hl[i]:
            l = []
            for j in range(w):
                if wl[j]:
                    l.append(a[i][j])
            print("".join(l))


if __name__ == '__main__':
    slove()
