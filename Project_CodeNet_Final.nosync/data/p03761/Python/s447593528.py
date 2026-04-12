import sys
from collections import Counter
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    N = int(readline())
    count = Counter(readline().decode('utf-8').strip())
    for _ in range(N-1):
        count &= Counter(readline().decode('utf-8').strip())
    ans = ''
    for key, value in count.items():
        ans += key*value
    ans = sorted(ans)
    print(''.join(map(str,ans)))





if __name__ == '__main__':
    main()
