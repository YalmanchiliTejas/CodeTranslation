from sys import exit

from copy import deepcopy
import numpy as np

import bisect

ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))


def main():
    s = input()
    
    for i in range(len(s)-1):
        if s[i:i+2] == "AC":
            print('Yes')
            exit()

    print('No')

main()