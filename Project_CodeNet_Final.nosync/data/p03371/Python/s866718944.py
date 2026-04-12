# coding: utf-8
# Your code here!
import sys

def main():
    A, B, C, X, Y = map(int, sys.stdin.readline().split())
    
    # 
    if C*2 >= A+B:
        ans = A*X + B*Y
    else:
        ans = min(X, Y) * C * 2
        # X: X - min(X, Y)
        # Y: Y - min(X< Y)
        ans += min(A*(X-min(X, Y)), C*2*(X-min(X, Y))) + min(B*(Y-min(X, Y)), C*2*(Y-min(X, Y)))
    print(ans)
    
if __name__ == "__main__":
    main()