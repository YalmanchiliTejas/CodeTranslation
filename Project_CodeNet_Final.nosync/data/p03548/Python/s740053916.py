import sys
sys.setrecursionlimit(4100000)
import math
INF = 10**9

def main():
    x,y,z = map(int, input().split())

    print((x-z)//(y+z))


if __name__ == '__main__':
    main()
