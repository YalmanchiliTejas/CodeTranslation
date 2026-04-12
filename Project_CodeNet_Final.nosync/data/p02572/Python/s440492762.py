def probC():
    N = input()
    A = list(map(int, input().split()))

    sum_tail = sum(A)

    total = 0
    for idx, i in enumerate(A):
        sum_tail -= A[idx]
        if idx + 1 == len(A):
            break
        total += i * sum_tail
    print(total % (10**9 + 7))


def main():
    probC()


if __name__ == '__main__':
    main()
