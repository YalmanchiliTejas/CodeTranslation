import bisect,copy,heapq,string
from collections import *
from math import *
from itertools import *
import sys
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

h, w = MAP()
a = [input()+'.' for i in range(h)]
a.append("."*(w+1))
i = j = 0
b = [['.']*(w+1) for i in range(h+1)]

if a[0][0] == '.':
        print("Impossible")
        exit()
else:
        while i < h or j < w:
                b[i][j] = '#'
 
                if a[i][j] == a[i+1][j] == a[i][j+1] == a[i+1][j+1] == '#':
                        print("Impossible")
                        exit()

                if i == h-1 and j == w-1:
                        break
                elif a[i+1][j] == '#':
                        i += 1
                elif a[i][j+1] == '#':
                        j += 1
                else: 
                        print("Impossible")
                        exit()

        for i in range(h):
                for j in range(w):
                        if a[i][j] != b[i][j]:
                                print("Impossible")
                                exit()
        print("Possible")