import sys


read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
s_readline = sys.stdin.readline

N = int(readline())
H = list(map(int, readline().split()))


def solve():

    ans = 1
    hmax = H[0]
    for i in range(1, N):
        if hmax <= H[i]:
            ans += 1
        hmax = max(hmax, H[i])

    print(ans)


if __name__ == '__main__':
    solve()
