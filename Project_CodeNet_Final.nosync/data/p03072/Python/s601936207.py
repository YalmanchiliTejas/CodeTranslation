import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n = f()[0]
    h = f()
    maxh = 0
    ans = 0
    for i in range(n):
        if(h[i]>=maxh):
             ans +=1
        maxh = max(h[i], maxh)
    print(ans)

solve()
