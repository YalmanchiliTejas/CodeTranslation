import sys
input = lambda: sys.stdin.readline().rstrip() 

def resolve():
    A, B, C, X, Y = map(int, input().split())

    ans = float('inf')
    for i in range(0, max(X, Y)*2+1, 2):
        ans = min(A*max(X-i//2, 0)+B*max(Y-i//2, 0)+C*i, ans)
    print(ans)

if __name__ == '__main__':
    resolve()
