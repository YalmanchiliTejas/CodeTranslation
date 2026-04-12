N = int(input())

s = input()


def fnc(x1, x2):
    pre = x1  # s[-1] の仮定
    curr = x2  # s[0] の仮定
    ans = []
    for i in range(N):
        if curr == 1:  # 羊
            if s[i] == 'o':
                nv = pre
            else:
                nv = (pre + 1) % 2
        else:  # 狼
            if s[i] == 'x':
                nv = pre
            else:
                nv = (pre + 1) % 2
        pre = curr
        curr = nv
        ans.append(pre)

    if pre == x1 and curr == x2:
        return ans
    else:
        return None


def solve():
    for i in [1, 0]:
        for j in [1, 0]:
            ans = fnc(i, j)
            if ans:
                return ans
    return None


if __name__ == '__main__':
    ans = solve()
    if not ans:
        print(-1)
        exit()

    for a in ans:
        print('S' if a else 'W', end='')
    print()
