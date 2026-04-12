# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys

def s():
    return raw_input().strip()
def n():
    return int(raw_input())
def d():
    return float(raw_input())

def ls():
    return raw_input().strip().split()
def ln():
    return map(int, raw_input().strip().split())
def ld():
    return map(float, raw_input().strip().split())

def fs():
    return [raw_input().strip() for i in xrange(input())]
def fn():
    return [int(raw_input().strip()) for i in xrange(input())]
def fd():
    return [float(raw_input().strip()) for i in xrange(input())]

H, W = ln()

panel = [['.'] + list(s()) + ['.'] for h in xrange(H)]

cur = 1

for i in xrange(H):
    for j in xrange(cur, W + 1):
        if panel[i][j] == '#':
            panel[i][j] = '.'
            cur = j
        else:
            break

success = True
for i in xrange(H):
    for j in xrange(1, W + 1):
        if panel[i][j] == '#':
            success = False
            break
    if not success:
        break

if success:
    print 'Possible'
else:
    print 'Impossible'
