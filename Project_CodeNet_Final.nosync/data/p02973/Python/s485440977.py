import sys
input = sys.stdin.readline
from bisect import bisect_left
from collections import deque

def main():
    N = int(input())
    counter = deque([])
    for _ in range(N):
        a = int(input())
        ind = bisect_left(counter, a)
        if ind == 0:
            counter.appendleft(a)
        else:
            counter[ind-1] = a
    print(len(counter))


if __name__ == '__main__':
    main()