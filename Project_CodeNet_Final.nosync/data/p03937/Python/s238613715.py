#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

def rl(proc=None):
    if proc is not None:
        return proc(sys.stdin.readline())
    else:
        return sys.stdin.readline().rstrip()

def srl(proc=None):
    if proc is not None:
        return map(proc, rl().split())
    else:
        return rl().split()

def go(a, x, y):
    if a[x][y] != '#':
        return []
    r = [(x, y)]
    while True:
        for tx, ty in ((x+1, y), (x, y+1)):
            if 0 <= tx < len(a) and 0 <= ty < len(a[0]) and a[tx][ty] == '#':
                x = tx
                y = ty
                break
        else:
            break
        r.append((x,y))
    return r


def main():
    R, C = srl(int)
    a = []
    for _ in xrange(R):
        a.append(rl())
    b = go(a, 0, 0)
    if not b or b[-1] != (R-1, C-1):
        print "Impossible"
        return
    s = sum(x.count('#') for x in a)
    print "Impossible" if s != len(b) else "Possible"

if __name__ == '__main__':
    main()
