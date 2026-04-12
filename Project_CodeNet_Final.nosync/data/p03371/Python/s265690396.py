import sys

def solve():
    input = sys.stdin.readline
    A, B, C, X, Y = map(int, input().split())
    C *= 2
    minCost = A * X + B * Y
    minCost = min(minCost, C * max(X, Y))
    if X >= Y: minCost = min(minCost, A * (X - Y) + C * Y)
    else: minCost = min(minCost, B * (Y - X) + C * X)
    print(minCost)


    return 0

if __name__ == "__main__":
    solve()