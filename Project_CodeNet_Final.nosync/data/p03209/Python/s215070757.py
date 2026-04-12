N, X = map(int, input().split())

a = [1]  # 厚さ
p = [1]  # パティの数
for i in range(N):
    a.append(2*a[-1] + 3)
    p.append(2*p[-1] + 1)


def f(n: int, x: int) -> int:
    """レベルnバーガーの下からx枚のパティの数
    """
    if x == 1:
        return 0 if n > 0 else 1
    elif x <= 1+a[n-1]:
        return f(n-1, x-1)
    elif x == 2 + a[n-1]:
        return p[n-1] + 1
    elif x <= 2*a[n-1] + 2:
        return p[n-1] + 1 + f(n-1, x - (2+a[n-1]))
    elif x == 2*a[n-1] + 3:
        return p[n]
    else:
        raise ValueError("xがレベルnバーガーの厚さより大きい, x={}, n={}".format(x, n))


if __name__ == "__main__":
    ans = f(N, X)
    print(ans)
