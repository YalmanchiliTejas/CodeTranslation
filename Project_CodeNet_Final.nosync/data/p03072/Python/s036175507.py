import sys

def ii2ss(n):
    return [sys.stdin.readline() for _ in range(n)]

def sp2nn(sp, sep=' '):
    return [int(s) for s in sp.split(sep)]

def ss2nn(ss):
    return [int(s) for s in list(ss)]

def main(ss):
    H = sp2nn(ss[1])
    hmax = -1
    count = 0
    for h in H:
        if h >= hmax:
            count += 1
            hmax = h
    print(count)

main(ii2ss(2))