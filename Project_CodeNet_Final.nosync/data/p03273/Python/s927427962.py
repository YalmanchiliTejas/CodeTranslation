import sys

ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: [int(x) for x in ns().split()]
nall = lambda: [int(x) for x in sys.stdin.readlines()]
sall = lambda: sys.stdin.readlines()

def main():
    h, w = na()
    a = sall()

    hs = []
    for i in range(h):
        if not [v for v in a[i] if v == '#']:
            hs.append(i)

    ws = []
    for i in range(w):
        if not [a[j][i] for j in range(h) if a[j][i] == '#']:
            ws.append(i)

    for i in range(h):
        p = False
        for j in range(w):
            if i in hs or j in ws:
                continue
            print(a[i][j], end='')
            p = True

        if p:
            print('')
            
main()
