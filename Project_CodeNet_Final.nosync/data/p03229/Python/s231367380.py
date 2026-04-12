import sys
input = sys.stdin.readline
INF = 10 ** 9
MOD = 10 ** 9 + 7
from collections import deque

def main(): 
    n = int(input())
    a = [int(input()) for _ in range(n)]
    a.sort()

    q = deque()
    q.append(a[0])
    l = 1
    r = n-1
    left = True
    high = True
    ans = 0
    while r - l > 0:
        if high:
            if left:
                ans += abs(a[r] - q[0])
                q.appendleft(a[r])
                r -= 1
                left = False
            else:
                ans += abs(a[r] - q[-1])
                q.append(a[r])
                r -= 1
                left = True
                high = False
        else:
            if left:
                ans += abs(a[l] - q[0])
                q.appendleft(a[l])
                l += 1
                left = False
            else:
                ans += abs(a[l] - q[-1])
                q.append(a[l])
                l += 1
                left = True
                high = True
    
    ans += max(abs(a[l] - q[0]), abs(a[l] - q[-1]))
    print(ans)

if __name__=='__main__':
    main()
