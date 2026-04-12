import sys
input = sys.stdin.readline
from operator import itemgetter
sys.setrecursionlimit(10000000)
INF = 10**30

def main():
    n, m = list(map(int, input().strip().split()))
    if n == m:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
