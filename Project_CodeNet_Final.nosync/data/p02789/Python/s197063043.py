# /usr/bin/python3
# -*- coding: utf-8 -*-
from queue import Queue
from queue import LifoQueue as Stack
from math import sqrt
from fractions import gcd

def lcm(a, b):
    return (a*b) // gcd(a,b)

def intinput():
    return int(input())

def mulinputs():
    return map(int,input().split())

def lineinputs(func=intinput):
    datas = []
    while True:
        try:
            datas.append(func())
        except EOFError:
            break
    return datas



N, M = mulinputs()

# 出力
if N == M:
    print('Yes')
else:
    print('No')


