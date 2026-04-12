def main():
    from itertools import cycle

    n = int(input())
    *a, = sorted(int(input()) for _ in range(n))

    half = n // 2
    h = reversed(a[:half])
    t = reversed(a[-half:])

    if n % 2 == 0:
        lis = []
        for e, o in zip(h, t):
            lis.append(e)
            lis.append(o)

        it = iter(lis)
        p = next(it)

        ret = 0
        for x in it:
            ret += abs(p - x)
            p = x

        print(ret)

    else:
        # 昇順ソートされたaを2つの山に分ける
        # xxx yy : 小を多く取る -> xyxyx
        # yは順序を気にしない
        # yとの差が小さくなるようなx（大きい方から2つ）を両端に置く
        # zz www : 大を多く取る -> wzwzw
        # zは順序を気にしない
        # zとの差が小さくなるようなw（小さい方から2つ）を両端に置く

        xs, ys = a[:-half], a[-half:]

        x = xs.pop()
        xs = [x] + xs

        cycl = cycle((xs, ys))

        p = next(cycl).pop()

        ret = 0
        for _ in range(n - 1):
            e = next(cycl).pop()
            ret += abs(p - e)
            p = e

        zs, ws = a[:half], a[half:]

        w, *ws = ws
        ws.append(w)

        cycl = cycle((ws, zs))

        p = next(cycl).pop()

        buf = 0
        for _ in range(n - 1):
            e = next(cycl).pop()
            buf += abs(p - e)
            p = e

        ret = max(ret, buf)

        print(ret)


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
