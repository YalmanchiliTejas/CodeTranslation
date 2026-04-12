#!/usr/bin/env python3

def main():
    (A,B,C,X,Y) = map(int,input().split())
    lim = max(X, Y)
    vmin = min(X, Y)
    minCost = 5000 * 10**5 * 2
    for t in range(lim+1):
        if t <= vmin:
            cost = (X - t) * A + (Y - t) * B + t * 2 * C
        elif X <= Y:
            cost = (Y - t) * B + t * 2 * C
        else:
            cost = (X - t) * A + t * 2 * C
        minCost = min(minCost, cost)
    print(minCost)
    

main()
