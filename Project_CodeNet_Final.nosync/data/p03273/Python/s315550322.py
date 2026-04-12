import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    h, w = f()
    lines = []
    for i in range(h):
        lines.append(input())
    
    rl = set()
    rc = set()
    for i in range(h):
        for j in range(w):
            if lines[i][j]== '#':
                rl.add(i)
                rc.add(j)
    
    rl = sorted(rl)
    rc = sorted(rc)

    for i in rl:
        for j in rc:
            print(lines[i][j], end = '')
        print()



solve()
