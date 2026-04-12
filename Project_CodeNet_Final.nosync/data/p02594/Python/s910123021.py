#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import glob

class InputGenerator(object):
    def __init__(self, input_path=None):
        if input_path != None:
            self.g = self.input_generator(input_path)
        else:
            self.g = None

    def input_generator(self, input_path):
        with open(input_path) as f:
            for line in f:
                yield line

    def get_input(self):
        if self.g == None:
            return input()
        else:
            return next(self.g)

def show_trace(s, trace):
    offset = 0
    arrow = ''
    for i in trace:
        if i != 0:
            print('{}{}'.format(arrow, s[offset:offset+i]), end='')
            arrow = ' -> '
        offset += i
    print('')

def solve(s):
    valid_term_list = ['dream', 'dreamer', 'erase', 'eraser']
    offset_candidate_list = [[0]]

    while offset_candidate_list != []:
        trace = offset_candidate_list.pop()
        offset = sum(trace)

        for c in valid_term_list:
            c_len = len(c)
            if c == s[offset:offset + c_len]:
                offset_candidate_list.append(trace + [c_len])
                if offset + c_len == len(s):
                    # show_trace(s, trace + [c_len])
                    return True

    return False

if __name__ == '__main__':
    TEST_FLAG = False

    if TEST_FLAG == True:
        file_path_list = sorted(glob.glob('test/*'))
    else:
        file_path_list = [None]

    for file_path in file_path_list:
        gen = InputGenerator(file_path)
        l = gen.get_input().rstrip()
        x = int(l)
        if x >= 30:
            print('Yes')
        else:
            print('No')
