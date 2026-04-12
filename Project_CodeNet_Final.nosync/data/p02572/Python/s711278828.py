import sys
def input(): return sys.stdin.readline().strip()
mod = 10**9+7

def main():
    N = int(input())
    A = list(map(int, input().split()))
    s = sum(A)
    ans = s * s
    for a in A: ans -= a * a
    print((ans // 2) % mod)


if __name__ == "__main__":
    main()
