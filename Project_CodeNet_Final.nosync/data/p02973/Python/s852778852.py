import bisect

if __name__ == '__main__':
    n = int(input())
    a = [int(input()) for _ in range(n)]
    colors = [a[-1]]
    ans = 1
    for x in reversed(a[:-1]):
        i = bisect.bisect_left(colors, x + 1)
        if i == ans:
            ans += 1
            colors.append(x)
        else:
            colors[i] = x
    print(ans)
