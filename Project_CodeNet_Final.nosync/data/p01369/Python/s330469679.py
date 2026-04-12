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
        left = set(['q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b'])
        while True:
            s = raw_input()
            if s == '#':
                break
            count = 0
            flg = s[0] in left
            for i in range(1, len(s)):
                if (s[i] in left) != flg:
                    flg = not flg
                    count += 1
            print count
                    
        return None

if __name__ == '__main__':
    m = Main()
    m.solve()