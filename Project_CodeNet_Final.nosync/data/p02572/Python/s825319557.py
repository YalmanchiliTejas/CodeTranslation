import sys
input = sys.stdin.readline
def main():
    N = int(input())
    A = list(map(int, input().split()))
    W = [0]*N
    W[0] = A[0]
    for i in range(1,N):
        W[i] += W[i-1] + A[i]
    ans = 0
    for i in range(N-1):
        ans += A[i]*(W[N-1] - W[i])
    print(ans%(10**9+7))

if __name__ == '__main__':
    main()