def f(x, m):
    return (x ** 2) % m


def main():
    n, x, m = map(int, input().split())
    lst = [[False, 0] for _ in range((m + 1))]
    lst[x] = [True, 1]
    res = [x]
    loop = 0

    for i in range(2, m + 1):
        x = f(x, m)
        if lst[x][0] == False:
            lst[x][0] = True
            lst[x][1] = i
            res.append(x)
        else:
            loop = i - lst[x][1]
            non_loop = lst[x][1] - 1
            break
    if loop == 0:
        print(sum(res[:n]))
        exit()
    ans = sum(res[:non_loop])
    ans += (n - non_loop) // loop * sum(res[non_loop:])
    ans += sum(res[non_loop:non_loop + (n - non_loop) % loop])
    print(ans)


if __name__ == "__main__":
    main()
