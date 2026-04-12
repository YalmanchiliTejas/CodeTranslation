#!/usr/bin/env python3
# -*- coding: utf-8 -*-
''' 
------------------------
author : iiou16
------------------------
'''

def main():
    N = int(input())
    H = list(map(int, input().split()))
    
    count = 0
    highest = 0
    for index in range(N):
        if highest <= H[index]:
            highest = H[index]
            count += 1
            

    print(count)


if __name__ == '__main__':
    main()