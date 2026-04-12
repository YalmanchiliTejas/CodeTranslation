from collections import deque

def main():
    import sys
    input = sys.stdin.readline

    MOD = 1000000007
    n = int(input())
    A = list(map(int, input().split()))
    tmp = sum(A)
    ans = 0
    for i in range(n-1):
        tmp -= A[i]
        ans += A[i]*tmp
    print(ans%MOD)

if __name__ == '__main__':
    main()
