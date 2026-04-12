import sys

def solve():
    input = sys.stdin.readline
    N = int(input())
    H = [int(h) for h in input().split()]
    ans = 1
    maxH = H[0]
    for i in range(1, N):
        if H[i] >= maxH:
            ans += 1
            maxH = H[i]
    print(ans)

    return  0

if __name__ == "__main__":
    solve()