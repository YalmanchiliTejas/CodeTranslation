def main():
    N = int(input())
    from collections import Counter
    A = [Counter(input()) for i in range(N)]
    ans = A[0]
    for a in A[1:]:
        ans &= a
    print("".join(sorted(ans.elements())))


if __name__ == '__main__':
    main()
