import sys
input = sys.stdin.readline
import bisect
from collections import deque

def main():
    N = int(input())
    use = deque([10**9+1])
    for _ in range(N):
        num = int(input())
        index = bisect.bisect_left(use,num)
        if index == 0:
            use.appendleft(num)
        else:
            use[index-1] = num
    
    print(len(use)-1)
    
if __name__ == "__main__":
    main()
