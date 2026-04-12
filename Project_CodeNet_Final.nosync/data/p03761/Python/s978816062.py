def main():
    orda = ord('a')

    N = int(input())

    ctr = [50] * 26
    for _ in range(N):
        s = input()
        t = [0] * 26
        for c in s:
            i = ord(c) - orda
            t[i] += 1

        for i, cnt in enumerate(t):
            ctr[i] = min(ctr[i], cnt)

    ans = ''
    for i, cnt in enumerate(ctr):
        ans += chr(i + orda) * cnt
    print(ans)


if __name__ == '__main__':
    main()

# import sys
# input = sys.stdin.readline
# 
# sys.setrecursionlimit(10 ** 7)
# 
# (int(x)-1 for x in input().split())
# rstrip()
#
# def binary_search(*, ok, ng, func):
#     while abs(ok - ng) > 1:
#         mid = (ok + ng) // 2
#         if func(mid):
#             ok = mid
#         else:
#             ng = mid
#     return ok
