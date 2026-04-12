import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n, k = f()
    ans = 0
    for b in range(k+1, n+1):
        if k!=0:
            ans += n//b * (b-k) + (n%b - (k-1) if n%b >k-1 else 0)
        else:
            ans += n
    
    print(ans)


solve()
