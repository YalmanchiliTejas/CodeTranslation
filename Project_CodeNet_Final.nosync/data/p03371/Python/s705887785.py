import sys

def solve():
    A, B, C, X, Y = map(int, input().split())
    C *= 2
    if X > Y:
        X, Y = Y, X
        A, B = B, A
    
    minCost = A * X + B * Y
    allC = Y * C
    XCYB = X * C + (Y - X) * B
    print(min(minCost, min(allC, XCYB)))
   
    return 0

if __name__ == "__main__":
    solve()