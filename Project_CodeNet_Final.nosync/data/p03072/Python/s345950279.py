# coding: utf-8
import numpy as np
from functools import lru_cache
import time

def main(): 
    if True:
        N = list(map(int, input().split()))
        H = list(map(int, input().split()))
    else:
        pass

    max = 0
    count = 0
    for h in H:
        if max <= h:
            count += 1
            max = h
    print(count)

if __name__ =='__main__':
    main()