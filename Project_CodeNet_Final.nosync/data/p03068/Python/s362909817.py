#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import scipy as sp

def main():
    while True:
        try:
            il = [input() for i in range(3)]
            N = int(il[0])
            S = il[1]
            K = int(il[2])

            res = ''.join(['*' if s != S[K-1] else s for s in S])

            print(res)


        except:
            break

if __name__ == '__main__':
    main()
