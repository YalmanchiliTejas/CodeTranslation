#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.setrecursionlimit(10**7)
from pprint import pprint as pp
from pprint import pformat as pf
#import pysnooper # @pysnooper.snoop() #TODO

import math
#from sortedcontainers import SortedList, SortedDict, SortedSet # no in atcoder
import bisect

class Solver:

    def __init__(self, n, s_list, t_list, u_list, v_list):
        self.n = n
        self.s_list = s_list
        self.t_list = t_list
        self.u_list = u_list
        self.v_list = v_list
        self.size = 64
        #self.size = 1 # debug
        self.bit_key = 1
        self.mode = 'l' # l or c
        self.ans = self.make_ans()

    def make_ans(self):
        ans = [None] * self.n
        for l in range(self.n):
            ans[l] = [0] * self.n
        return ans

    def print_ans(self):
        for l in range(self.n):
            for c in range(self.n):
                print(self.ans[l][c], end=" ")
            print("")


    def add_straight(self, key, value):
        if not value:
            return
        if self.mode == 'l':
            for c in range(self.n):
                self.ans[key][c] |= self.bit_key
        else:
            for l in range(self.n):
                self.ans[l][key] |= self.bit_key

    def add(self, key, sub_key, value):
        if not value:
            return
        if self.mode == 'l':
            l, c = key, sub_key
        else:
            l, c = sub_key, key
        self.ans[l][c] |= self.bit_key

    def run(self):
        try:
            for bit in range(self.size):
                self.bit_key = 1 << bit
                self.solve_for_bit()
        except RuntimeError as err:
            #raise err # debug
            return False
        return True

    def solve_for_bit(self):
        # determine
        self.mode = 'l'
        filled_l, ambiguous_l = self.determine(self.s_list, self.u_list)
        #print('filled_l, ambiguous_l') # debug
        #print(filled_l, ambiguous_l) # debug
        self.mode = 'c'
        filled_c, ambiguous_c = self.determine(self.t_list, self.v_list)
        #print('filled_c, ambiguous_c') # debug
        #print(filled_c, ambiguous_c) # debug
        #print('self.ans') # debug
        #self.print_ans() # debug
        # check
        if filled_l[0] and filled_c[1] or filled_l[1] and filled_c[0]:
            #print('hoge') # debug
            raise RuntimeError
        # fill 1 straight or like checker
        if len(ambiguous_l) == 1:
            self.handle_straight('l', filled_l, ambiguous_l, filled_c, ambiguous_c)
        elif len(ambiguous_c) == 1:
            self.handle_straight('c', filled_c, ambiguous_c, filled_l, ambiguous_l)
        else:
            self.checker_fill(ambiguous_l, ambiguous_c)

    def determine(self, l1, l2):
        filled = [False, False]
        ambiguous = [] # (key, wanted)
        for key in range(self.n):
            st = l1[key]
            uv = 1 if l2[key] & self.bit_key else 0
            if st == uv:
                ambiguous.append((key, uv))
                continue
            filled[uv] = True
            self.add_straight(key, uv)
        return filled, ambiguous

    def handle_straight(self, mode, filled, ambiguous, sub_filled, sub_ambiguous):
        #print('self.ans') # debug
        #print(self.ans) # debug
        self.mode = mode
        key, wanted = ambiguous[0]
        ok = False
        if sub_filled[wanted]:
            ok = True
        for sub_key, sub_wanted in sub_ambiguous:
            if filled[sub_wanted]:
                # sub_wanted is satisfied, so use for wanted
                self.add(key, sub_key, wanted)
                ok = True
            else:
                # satisfy sub_wanted
                self.add(key, sub_key, sub_wanted)
                if wanted == sub_wanted:
                    ok = True
        if not ok:
            raise RuntimeError

    def checker_fill(self, ambiguous_l, ambiguous_c):
        self.mode = 'l'
        for il, (l_key, _) in enumerate(ambiguous_l):
            for ic, (c_key, _) in enumerate(ambiguous_c):
                v = (il + ic) % 2 == 0
                #print('l_key, c_key', l_key, c_key) # debug
                self.add(l_key, c_key, v)


if __name__ == '__main__':
    n = int(input())
    s_list = list(map(int, input().split()))
    t_list = list(map(int, input().split()))
    u_list = list(map(int, input().split()))
    v_list = list(map(int, input().split()))
    #print('n, s_list, t_list, u_list, v_list') # debug
    #print(n, s_list, t_list, u_list, v_list) # debug
    solver = Solver(n, s_list, t_list, u_list, v_list)
    ans = solver.run()
    if ans is False:
        print(-1)
    else:
        solver.print_ans()

    #print('\33[32m' + 'end' + '\033[0m') # debug
