import sys

def solve():
    input = sys.stdin.readline
    A, B, C, X, Y = map(int, input().split())
    if X > Y:
        X, Y = Y, X
        A, B = B, A
    C *= 2
    AB = A * X + B * Y
    allC = C * Y
    CB = C * X + B * (Y - X)
    print(min([AB, allC, CB]))
    
    
    return 0

if __name__ == "__main__":
    solve()