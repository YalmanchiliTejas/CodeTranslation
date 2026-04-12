def f_b():
    n, *h = map(int, open(0).read().split())
    c = n
    for i in range(1, n):
        for j in range(i):
            if h[j]>h[i]:
                c -= 1; break
    print(c)

if __name__ == "__main__":
    f_b()
