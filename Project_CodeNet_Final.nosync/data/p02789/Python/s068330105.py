#!/usr/bin/env python3
# -*- coding: utf-8 -*-
''' 
------------------------
author : iiou16
------------------------
'''

def main():
    N, M = list(map(int, input().split()))

    if N == M:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()