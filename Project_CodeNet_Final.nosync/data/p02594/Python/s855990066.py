import sys
import os
import itertools
import numpy as np
from collections import deque

def main():
    if os.getenv("ENV")=='LOCAL':
        sys.stdin = open(os.path.dirname(__file__)+'/input.txt', 'r')

    X=int(input())

    if X>=30:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
