import sys
import os

H, W = map(int,input().split())
cntS = 0
for i in range(H):
    cntS += list(input()).count("#")

if cntS == H+W-1:
    print("Possible")
else:
    print("Impossible")
