import sys
import numpy as np
def input(): return sys.stdin.readline().rstrip()
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(mi())


def main():
    n, k = mi()
    ans = 0
    for i in range(k+1, n+1):
        ans += (n//i)*(i-k)
        if k == 0:
            ans -= 1
        ans += max(n%i-k+1, 0)
    print(ans)



    
        
if __name__ == '__main__':
    main()