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
        h, w = map(int, input().split())
        a = []
        for i in range(h):
            a.append(list(input()))
        # print(h)
        # print(w)
        # print(a)

        hash = []
        for i in range(h):
            for j in range(w):
                if a[i][j] == '#':
                    hash.append((i, j))
        # print(hash)
                
        queue = [(0, 0, [(0, 0)])]
        flag = False
        while queue:
            # print(queue)
            i, j, hist = queue.pop(0)
            if (i, j) == (h - 1, w - 1) and a[i][j] == '#' and hist == hash:
                flag = True
                break
            else:
                if i + 1 < h and a[i+1][j] == '#':
                    queue.append((i + 1, j, hist + [(i + 1, j)]))
                if j + 1 < w and a[i][j+1] == '#':
                    queue.append((i, j + 1, hist + [(i, j + 1)]))
        if flag:
            print('Possible')
        else:
            print('Impossible')
        
        return None

if __name__ == '__main__':
    m = Main()
    m.solve()
