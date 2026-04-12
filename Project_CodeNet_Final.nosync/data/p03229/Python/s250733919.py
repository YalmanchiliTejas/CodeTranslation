import sys
input = sys.stdin.readline
from operator import itemgetter
sys.setrecursionlimit(10000000)

def main():
    n = int(input().strip())
    a = [0] * n
    for i in range(n):
        a[i] = int(input().strip())
    a = sorted(a)
    ans = 0
    if n % 2 == 0:
        kei1 = sorted([1, -1] + [-2] * ((n-2)//2) + [2] * ((n-2)//2))
        for i in range(n):
            ans += a[i] * kei1[i]
    else:
        kei1 = sorted([-1] * 2 + [2] * (n//2) + [-2] * (n//2 - 1))
        kei2 = sorted([1] * 2 + [2] * (n//2-1) + [-2] * (n//2))
        ans2 = 0
        for i in range(n):
            ans += a[i] * kei1[i]
            ans2 += a[i] * kei2[i]
        ans = max(ans, ans2)

    print(ans)

if __name__ == '__main__':
    main()
