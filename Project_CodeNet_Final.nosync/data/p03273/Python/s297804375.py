#!/usr/bin/env python3

def solve(h, w, a):
    ret = []
    for r in a:
        left = False
        for c in r:
            if c == '#':
                left = True
                break
        if left:
            ret.append(r)
    ret2 = ['' for _ in range(len(ret))]
    for j in range(w):
        left = False
        for i in range(len(ret)):
            if ret[i][j] == '#':
                left = True
                break
        if left:
            for i in range(len(ret)):
                ret2[i] += ret[i][j]
    for r in ret2:
        print(r)
    return


def main():
    h, w = map(int, input().split())
    a = []
    for i in range(h):
        a.append(str(input()))
    solve(h, w, a)
    # Failed to predict input format
    pass

if __name__ == '__main__':
    main()
