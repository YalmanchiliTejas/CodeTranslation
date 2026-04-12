#!/usr/bin/env python3

def main():
    A, B, C, X, Y = map(int, open(0).read().split())
    
    S = []
    for i in range(0, 2*max(X, Y)+1):
        S.append(A*max(0, X - i//2) + B*max(0, Y - i//2) + C*i)
    print(min(S))

main()