import sys
from collections import Counter

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    n = int(readline())
    S = [readline().strip() for _ in range(n)]

    vec = [INF] * 26
    for s in S:
        counter = Counter(s)
        for i in range(26):
            c = chr(i + ord('a'))
            if vec[i] > counter[c]:
                vec[i] = counter[c]

    ans = []
    for i, n in enumerate(vec):
        ans.extend([chr(i + ord('a'))] * n)

    print(''.join(ans))
    return


if __name__ == '__main__':
    main()
