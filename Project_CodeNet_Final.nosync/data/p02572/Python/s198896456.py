import sys

mod = 10**9+7
def I(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def main():
    n = I()
    A = LI()
    A_sum = sum(A)
    ans = 0
    for i in range(n-1):
        A_sum -= A[i]
        ans += A[i]*A_sum
        ans %= mod
    print(ans)

if __name__ == '__main__':
    main()