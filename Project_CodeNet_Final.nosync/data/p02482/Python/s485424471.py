#!/usr/bin/env python
# coding: utf-8


def main():
    a, b = [int(x) for x in raw_input().split(" ")]
    if a < b:
        print "a < b"
    elif a > b:
        print "a > b"
    else:
        print "a == b"


if __name__ == '__main__':
    main()