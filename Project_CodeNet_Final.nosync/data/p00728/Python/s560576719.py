while True:
    N = int(input())
    if N == 0:
        break
    S = [ int(input()) for i in range(N)]
    S.sort()
    del S[len(S) - 1]
    del S[0]
    print(sum(S) // len(S))

