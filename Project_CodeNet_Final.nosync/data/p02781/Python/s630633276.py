def main():
    N = input()
    K = int(input())
    t = len(N)
    if K == 1:
        return (t - 1) * 9 + int(N[0])
    elif K == 2:
        if t < 2:
            return 0
        r = (t - 1) * (t - 2) * 81 // 2
        r += (int(N[0]) - 1) * (t - 1) * 9
        for i, v in enumerate(N):
            if i < 1:
                continue
            if v != '0':
                r += int(v) + 9 * (t - 1 - i)
                return r
        return r
    else:
        if t < 3:
            return 0
        r = (t - 1) * (t - 2) * (t - 3) * 729// 6
        r += (int(N[0]) - 1) * (t - 1) * (t - 2) * 81 // 2
        second = False
        for i, v in enumerate(N):
            if i < 1:
                continue
            if v != '0' and not second:
                r += (int(v)-1) * (t - 1 - i) * 9
                r += (t - 1 - i) * (t - 2 - i) * 81 // 2
                second = True
            elif v != '0':
                r += int(v) + 9 * (t - 1 - i)
                return r
        return r
print(main())
