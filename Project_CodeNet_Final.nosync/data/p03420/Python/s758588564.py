import sys
def main():
    input = sys.stdin.readline
    N,K = map(int, input().split())
    
    ans = 0
    for b in range(K+1, N+1):
        div, mod = divmod(N, b)
        one = b - K
        ans += div * one
        ans += max(0, mod - K + (1 if K!=0 else 0))
    print(ans)

if __name__ == '__main__':
    main()