def main():
    N = int(input())
    A = [input() for i in range(N)]
    from collections import Counter
    c = Counter(A[0])
    for a in A[1:]:
        d = Counter(a)
        c = c & d
    print("".join(sorted(c.elements())))


if __name__ == '__main__':
    main()
