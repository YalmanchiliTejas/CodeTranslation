import sys
from operator import itemgetter
import collections


def main():
    input = sys.stdin.readline
    s, n = map(int, input().split())
    print("Yes" if s==n else "No")

    
if __name__ == '__main__':
    main()
