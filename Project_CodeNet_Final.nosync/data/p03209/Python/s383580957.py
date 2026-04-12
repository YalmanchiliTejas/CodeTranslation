def solve(string):
    n, x = map(int, string.split(" "))
    t = ["P"]
    for _ in range(10):
        t.append("B{}P{}B".format(t[-1], t[-1]))
    l, p = [1], [1]
    for _ in range(n):
        l.append(2 * l[-1] + 3)
        p.append(2 * p[-1] + 1)

    def rec(i, x):
        if i <= 10:
            return t[i][:x].count("P")
        if x > l[i - 1] + 2:
            return p[i - 1] + 1 + rec(i - 1, x - l[i - 1] - 2)
        elif x == l[i - 1] + 2:
            return p[i - 1] + 1
        else:
            return rec(i - 1, x - 1)

    return str(rec(n, x))


if __name__ == '__main__':
    print(solve(input()))
