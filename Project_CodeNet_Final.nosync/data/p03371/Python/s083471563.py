import sys
input = sys.stdin.readline
def main():
    A, B, C, X, Y =map(int, input().split())
    ans = min(min(2*X*C + max((Y-X)*B, 0), 2*Y*C + max((X-Y)*A, 0)), A*X + B*Y)
    print(ans)    

if __name__ == '__main__':
    main()