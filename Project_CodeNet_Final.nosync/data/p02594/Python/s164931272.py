#!python3

import sys
iim = lambda: map(int, sys.stdin.readline().rstrip().split())

def resolve():
    X = int(input())

    print("Yes" if X >= 30 else "No")

if __name__ == "__main__":
    resolve()
