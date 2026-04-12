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
            n = input()
            if n == 0:
                break
            p = []
            for i in range(n):
                p.append(input())
            print (sum(p) - min(p) - max(p)) / (n - 2)
        
        return None

if __name__ == '__main__':
    m = Main()
    m.solve()