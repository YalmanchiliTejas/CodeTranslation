#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import itertools
import math
from collections import Counter, defaultdict

class Main(object):
    
    def __init__(self):
        pass

    def solve(self):
        '''
        insert your code
        '''
        while True:
            n, a, b, c, x = map(int, raw_input().split())
            if n == 0 and a == 0 and b == 0 and c == 0 and x == 0:
                break
            y = map(int, raw_input().split())
            count = 0
            flg = False
            for i in range(len(y)):
                while x != y[i]:
                    x = (a * x + b) % c
                    count += 1
                    if count > 10000:
                        flg = True
                        break
                if flg:
                    print -1
                    break
                if i != len(y) - 1:
                    x = (a * x + b) % c
                    count += 1
            else:
                print count


        
        return None

if __name__ == '__main__':
    m = Main()
    m.solve()