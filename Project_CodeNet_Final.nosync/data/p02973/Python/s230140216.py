def main():
    from heapq import heappop, heappush
    import sys

    input = sys.stdin.readline

    N = int(input())
    a = [int(input()) for _ in range(N)]

    def binary_search(b, x):
        ok, ng = len(b), -1
        while abs(ok - ng) > 1:
            mid = (ok + ng) // 2
            if b[mid] < x:
                ok = mid
            else:
                ng = mid
        return ok

    b = [-1]
    for x in a:
        i = binary_search(b, x)
        if i == len(b):
            b.append(x)
        else:
            b[i] = x

    ans = len(b)

    print(ans)


if __name__ == '__main__':
    main()

# import sys
#
# sys.setrecursionlimit(10 ** 7)
#
# input = sys.stdin.readline
# rstrip()
# int(input())
# map(int, input().split())
