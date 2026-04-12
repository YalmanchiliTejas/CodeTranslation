import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def main():
    n = int(input())
    xx = list(map(int, input().split()))
    cxx = sorted(xx)
    m0 = cxx[n // 2 - 1]
    m1 = cxx[n // 2]
    for x in xx:
        if x <= m0:
            print(m1)
        else:
            print(m0)

main()
