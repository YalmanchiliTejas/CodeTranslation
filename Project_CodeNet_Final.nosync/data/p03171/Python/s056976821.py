def main():
    N = int(input())
    A = list(map(int, input().split()))
    c = [0] * N
    for r in reversed(range(N)):
        ar = A[r]
        c[r] = t = ar
        for l in range(r + 1, N):
            c[l] = t = max(ar - c[l], A[l] - t)
    
    print(c[-1])


main()
