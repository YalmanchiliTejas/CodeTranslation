from sys import stdin


def main() -> None:
    n = int(next_str())
    a = [int(input()) for _ in range(n)]
    a.sort()

    i = 0
    j = len(a) - 1
    flg = False
    left = right = 0
    ans = 0
    while i <= j:
        if not flg:
            if (a[-1] * 2 - a[0] - a[1]) > (a[-1] + a[-2] - a[0] * 2):
                left = right = a[-1]
                j -= 1
            else:
                left = right = a[0]
                i += 1
            flg = True
        else:
            best = (0, 0)
            for k, v in enumerate([left - a[i], left - a[j], right - a[i], right - a[j]]):
                if best[1] < abs(v):
                    best = (k, abs(v))
            ans += best[1]
            if best[0] == 0:
                left = a[i]
                i += 1
            elif best[0] == 1:
                left = a[j]
                j -= 1
            elif best[0] == 2:
                right = a[i]
                i += 1
            elif best[0] == 3:
                right = a[j]
                j -= 1

    print(ans)


def next_str() -> str:
    result = ""
    while True:
        tmp = stdin.read(1)
        if tmp.strip() != "":
            result += tmp
        elif tmp != '\r':
            break
    return result


if __name__ == '__main__':
    main()