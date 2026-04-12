import sys
import os
import math

MOD = 10**9+7

def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    X, Y, Z = list(map(int, sys.stdin.readline().split()))
    print((X-Z)//(Y+Z))


if __name__ == '__main__':
    main()
