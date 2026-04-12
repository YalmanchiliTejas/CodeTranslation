import sys

def input():
    return sys.stdin.readline()[:-1]

def mi():
    return map(int, input().split())

def ii():
    return int(input())

def main():
    A, B, C, X, Y = mi()

    if A+B > 2*C:
        if X > Y:
            ans = 2*Y*C+min((X-Y)*A, (X-Y)*2*C)
        else:
            ans = 2*X*C+min((Y-X)*B, (Y-X)*2*C)
    else:
        ans = A*X+B*Y
    print(ans)

if __name__ == '__main__':
    main()
