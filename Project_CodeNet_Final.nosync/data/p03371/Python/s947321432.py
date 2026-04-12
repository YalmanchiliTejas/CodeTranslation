#!/usr/bin/env python3

def solve(A: int, B: int, C: int, X: int, Y: int):
    ans = 10**9
    if A + B < 2 * C:#C=0
        ans = A*X + B*Y
    else:#C>1
        #Aを2*Cで補うときの利益 > Bを2*Cで補うときの利益
        if (A-2*C)*X + B*max(Y-X, 0) > (B-2*C)*Y + A*max(X-Y, 0):
            #A=0
            ans = 2*C*X + max(Y-X, 0)*B
        else:#B=0
            ans = 2*C*Y + max(X-Y, 0)*A
        if 2*C < A and 2*C < B:
            ans = min(ans, 2*C*max(X,Y))
    print(ans)

def main():
    A, B, C, X, Y = map(int, input().split())
    solve(A, B, C, X, Y)

if __name__ == '__main__':
    main()
