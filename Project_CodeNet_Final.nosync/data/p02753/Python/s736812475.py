# -*- coding: utf-8 -*-

import sys

def prob_a(s):
    chars = list(s)
    tmpc = chars[0]
    for c in chars[1:]:
        if c == tmpc:
            continue
        else:
            print('Yes')
            return 0
    print('No')

if __name__ == '__main__':
    s = input()
    prob_a(s)
