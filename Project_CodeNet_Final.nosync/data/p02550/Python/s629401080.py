import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N, X, M = [int(x) for x in input().split()]

    x = {}

    ruiseki = [0] * (M + 1)

    cnt = 1
    ans = X
    c = X
    ruiseki[1] = ans
    while cnt < N:
        if c == 0:
            print(ans)
            return
        next = c ** 2 % M
        if next in x.keys():
            y = x[next]
            # print(ruiseki)
            # print(cnt, y)
            if N == cnt:
                print(ans + next)
                return
            loop = ruiseki[cnt] - ruiseki[y - 1]
            loopcnt = cnt - y + 1
            ans += ((N - cnt) // loopcnt) * loop
            # print(ans)
            amari = (N - cnt) % loopcnt
            # print(amari, loop, loopcnt)
            if amari != 0:
                ans += ruiseki[y - 1 + amari] - ruiseki[y - 1]
                # print(ans)
            break

        ans += next
        cnt += 1
        ruiseki[cnt] = next
        ruiseki[cnt] += ruiseki[cnt - 1]
        c = next
        x[next] = cnt

    print(ans)


if __name__ == '__main__':
    main()
