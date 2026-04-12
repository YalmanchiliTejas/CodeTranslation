from sys import stdin
rs = lambda : stdin.readline().strip()
ri = lambda : int(rs())
ril = lambda : list(map(int, rs().split()))

def main():
    N, K = map(int, input().split())
    ans = K - N if K == 0 else 0
    for b in range(K + 1, N + 1):
        c = (N - K) // b
        ans += (b - K) * c + min(N - c * b + 1, b) - K
    print(ans)

if __name__ == '__main__':
    main()
