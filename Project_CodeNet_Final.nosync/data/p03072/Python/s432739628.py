def solve(string):
    n, *h = map(int, string.split())
    count = 1
    for i in range(1, n):
        if max(h[:i]) <= h[i]:
            count += 1
    return str(count)


if __name__ == '__main__':
    print(solve('\n'.join([input(), input()])))
