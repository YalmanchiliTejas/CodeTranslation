import math
import sys
input = sys.stdin.readline


def main():
    X, Y, Z = map(int, input().split())

    X -= Z
    print(X//(Y+Z))       


if __name__ == '__main__':
    main()