import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    n = int(readline())
    s = str(readline().rstrip().decode('utf-8'))
    k = int(readline())
    r = s[k-1]
    ans = []
    for i in range(n):
        if s[i] != r:
            ans.append("*")
        else:
            ans.append(r)
    print("".join(ans))


if __name__ == '__main__':
    solve()
