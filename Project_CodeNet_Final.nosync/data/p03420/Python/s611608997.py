import sys
input=sys.stdin.readline

def main():
    N,K = map(int, input().split())

    if K == 0:
        print(N**2)
        return

    ans = 0
    for b in range(K+1,N+1):
        ans += ((b-1) - (K-1)) * (N//b) + max(0, N%b - (K-1))

    print(ans)

if __name__ == '__main__':
    main()
