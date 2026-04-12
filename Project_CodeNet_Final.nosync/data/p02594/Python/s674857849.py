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

def solve(gen):
    l = gen.get_input().rstrip()
    x = int(l)
    if x >= 30:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    test_flag = len(sys.argv) > 1

    if test_flag == True:
        file_path_list = sorted(glob.glob('test/*'))
    else:
        file_path_list = [None]

    for file_path in file_path_list:
        gen = InputGenerator(file_path)
        solve(gen)
