#!/usr/bin/env python
# coding: utf-8

def ri():
    return int(input())

def rl():
    return list(input().split())

def rli():
    return list(map(int, input().split()))

def main():
    s = input()
    if (s == 'AAA' or s == 'BBB'):
        print("No")
    else:
        print("Yes")


if __name__ == '__main__':
    main()
