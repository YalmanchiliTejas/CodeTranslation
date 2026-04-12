#!/usr/bin/env python3
# from typing import *

YES = 'Yes'
NO = 'No'

def solve(X):
    return YES if X >= 30 else NO

def main():
    X = int(input())
    a = solve(X)
    print(a)

if __name__ == '__main__':
    main()
