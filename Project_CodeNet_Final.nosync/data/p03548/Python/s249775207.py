#!/usr/bin/env python
# coding: utf-8


def main():
    x, y, z = list(map(int, input().split()))
    print((x - z) // (y+z))


if __name__ == '__main__':
    main()
