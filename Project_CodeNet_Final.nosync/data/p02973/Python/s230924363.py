import bisect
import sys
from collections import deque

def main():
    input = sys.stdin.readline
    N = int(input())
    A = deque([int(input())])
    for k in range(N-1):
        t = int(input())
        if A[0] >= t:
            A.appendleft(t)
        else:
            A[bisect.bisect_left(A,t)-1] = t
    print(len(A))

if __name__ == '__main__':
    main()
