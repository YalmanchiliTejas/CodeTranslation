import sys
from collections import deque
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    h, w = map(int, input().split())
    c = 0
    for _ in range(h):
        a = list(input())
        c += a.count("#")
    print(("Possible" if c == h + w - 1 else "Impossible"))


if __name__ == '__main__':
    main()