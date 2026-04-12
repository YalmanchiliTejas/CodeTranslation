def func():
    N = int(input())
    H = list(map(int, input().split()))

    count = N

    for i in range(1, N):
        for k in range(i):
            if (H[k] > H[i]):
                count -= 1
                break

    print(count)


if __name__ == '__main__':
    func()
