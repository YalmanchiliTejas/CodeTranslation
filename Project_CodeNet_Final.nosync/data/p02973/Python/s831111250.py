import sys
input = sys.stdin.buffer.readline
import bisect
from collections import deque

def main():
    N = int(input())
    INF = 10**10
    col = deque([INF])
    for _ in range(N):
        num = int(input())
        ind = bisect.bisect_left(col,num)
        if ind == 0:
            col.appendleft(num)
        else:
            col[ind-1] = num
    
    print(len(col)-1)

if __name__ == "__main__":
    main()
