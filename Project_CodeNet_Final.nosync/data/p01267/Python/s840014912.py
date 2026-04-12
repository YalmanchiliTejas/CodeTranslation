import sys
import collections


while True:
    N, A, B, C, X = map(int, sys.stdin.readline().split())
    if N == 0:
        break
    
    x = X
    
    count = 0
    Y = map(int, sys.stdin.readline().split())
    before = -1
    for y in Y:
        if before == y:
            x = (A * x + B) % C
            count += 1
        while x != y and count <= 10000:
            x = (A * x + B) % C
            count += 1
        before = x
    if count <= 10000:
        print count
    else:
        print -1