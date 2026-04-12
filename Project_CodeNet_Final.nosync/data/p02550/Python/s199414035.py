def resolve():
    n, x, m = map(int, input().split())
    a = [None] * m
    s = [x]
    a[x] = 0
    ans = x
    for i in range(1, n):
        x = pow(x, 2, m)
        if a[x] is None:
            ans += x
            a[x] = i
            s.append(ans)
        else:
            past = a[x]
            d = i - past
            ans += x
            s.append(ans)
            diff = s[i] - s[past]
            ans += ((n - i - 1) // d) * diff
            ans += s[past + ((n - i - 1) % d)] - s[past]
            break
    print(ans)


if __name__ == '__main__':
    resolve()
