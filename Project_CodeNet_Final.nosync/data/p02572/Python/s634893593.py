
#!/usr/bin/python
# -*- coding: utf-8 -*-

# def
def int_mtx(N):
    x = []
    for _ in range(N):
        x.append(list(map(int,input().split())))
    return np.array(x)

def str_mtx(N):
    x = []
    for _ in range(N):
        x.append(list(input()))
    return np.array(x)

def int_map():
    return map(int,input().split())

def int_list():
    return list(map(int,input().split()))

def print_space(l):
    return print(" ".join([str(x) for x in l]))

# import
import numpy as np
import collections as col

# main code
N = int(input())
A = int_list()

sumlist = []
sumlist.append(A[0])

for i in range(1,N):
    sumlist.append((sumlist[i-1]+A[i])%(10**9+7))

a = 0

for i in range(0,N-1):
    a += (A[i]*(sumlist[N-1]-sumlist[i]))%(10**9+7)

print(a%(10**9+7))