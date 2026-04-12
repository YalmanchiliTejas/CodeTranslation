import sys


def main():
    h, w = map(int, input().split())
    a = [input().strip() for i in range(h)]

    rd = [False] * h
    cd = [False] * w

    for i in range(h):
        rd[i] = all(a[i][j] == '.' for j in range(w))

    for j in range(w):
        cd[j] = all(a[i][j] == '.' for i in range(h))

    for i in range(h):
        line = ''
        for j in range(w):
            if rd[i] or cd[j]:
                continue
            line += a[i][j]
        if line:
            print(line)


main()
