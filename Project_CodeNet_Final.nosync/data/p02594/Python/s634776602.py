#!/usr/bin/env python3


def main():
    import sys

    input = sys.stdin.readline

    X = int(input())
    if X >= 30:
        print('Yes')
    else:
        print('No')
        

if __name__ == '__main__':
    main()
