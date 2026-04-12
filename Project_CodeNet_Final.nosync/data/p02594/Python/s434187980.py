
#!/usr/bin/python
# -*- coding: utf-8 -*-

# def
def int_mtx(N):
    x = []
    for _ in range(N):
        x.append(list(input()))
    return x

def int_map():
    return map(int,input().split())

def int_list():
    return list(map(int,input().split()))

def print_space(l):
    return print(" ".join([str(x) for x in l]))

# import
import numpy as np



# main code
X = int(input())

if X >= 30:
    print("Yes")
else:
    print("No")

