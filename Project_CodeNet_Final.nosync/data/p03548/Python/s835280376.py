import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    x,y,z = f()
    cnt = x//(y+z)

    if  x%(y+z) >= z:
        print(cnt)
    else:
        print(cnt-1)


solve()
