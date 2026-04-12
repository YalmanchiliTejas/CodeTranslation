#! usr/bin/env python
# -*- coding: utf-8 -*-


def main():
    h, w = map(int, input().split())
    g = [list(input()) for i in range(h)]

    r = []
    for i in range(h):
        if "#" not in g[i]:
            r.append(i)

    cnt = 0
    for i in r:
        g.pop(i-cnt)
        cnt += 1

    c = []
    for i in range(w):
        for j in range(h-len(r)):
            if g[j][i] == "#":
                break
        else:
            c.append(i)

    for i in range(h-len(r)):
        cnt = 0
        for j in c:
            g[i].pop(j-cnt)
            cnt += 1

    for i in range(h-len(r)):
        print("".join(g[i]))


if __name__ == '__main__':
    main()
