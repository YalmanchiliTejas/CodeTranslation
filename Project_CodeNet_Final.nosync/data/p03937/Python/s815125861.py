#!/usr/bin/env python3
import sys

H, W = map(int, input().split())
A = []
for i in range(H):
    temp = list(input())
    A.append(temp)

def is_sharp(i, j):
    # print(i,j)
    if i<0 or j<0 or i>=H or j>=W:
        return False
    if A[i][j] == "#":
        return True
    else:
        return False

def ok(i,j):
    if is_sharp(i-1, j) and is_sharp(i,j-1):
        return False
    if is_sharp(i+1, j) and is_sharp(i,j+1):
        return False
    return True

for i in range(H):
    for j in range(W):
        if is_sharp(i,j) and (not ok(i,j)):
            print("Impossible")
            sys.exit(0)
print("Possible")
