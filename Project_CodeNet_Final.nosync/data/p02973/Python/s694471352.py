import sys
from bisect import bisect_left
from collections import deque


def main():
    input = sys.stdin.buffer.readline
    n = int(input())
    a = [int(input()) for _ in range(n)]
    pile = deque()
    for i in range(n):
        index = bisect_left(pile, a[i])
        if index == 0:
            pile.appendleft(a[i])
        else:
            pile[index - 1] = a[i]
    print(len(pile))


if __name__ == "__main__":
    main()
