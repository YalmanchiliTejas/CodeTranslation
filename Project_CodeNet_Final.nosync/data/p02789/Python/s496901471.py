import sys
from pprint import pprint

def solve(n, m):
    print("Yes" if n == m else "No")

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().strip().split(" "))
    solve(n, m)