def main():
    H, W = map(int, input().split())
    a = [input() for _ in range(H)]

    show_r = []
    show_c = []

    for r, row in enumerate(a):
        show_r.append(any(c == '#' for c in row))

    for c, col in enumerate(zip(*a)):
        show_c.append(any(c == '#' for c in col))

    ans = []
    for r in range(H):
        t = ''
        for c in range(W):
            if show_r[r] and show_c[c]:
                t += a[r][c]
        if t:
            ans.append(t)

    print(*ans, sep='\n')


if __name__ == '__main__':
    main()

# import sys
#
# sys.setrecursionlimit(10 ** 7)
#
# input = sys.stdin.readline
# rstrip()
# int(input())
# map(int, input().split())
