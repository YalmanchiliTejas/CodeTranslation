# -*- coding: utf-8 -*-
import sys
H, W = map(int, input().split(' '));

board = []
flags = [ True for x in range(W)]
for i in range(H):
    line = list(input())
    if ( '#' in line ):
        board.append(line)
        flags = [ f and s == '.' for s,f in zip(line, flags) ]

j = 0
for b in board:
    for l,flag in zip(b,flags):
        if not flag:
            sys.stdout.write(l)
    print()