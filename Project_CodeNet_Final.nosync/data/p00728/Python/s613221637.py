while True:
    N = int(input())
    if N == 0:
        break
    S = []
    for i in range(N):
        S.append(int(input()))
    a = sum(S)-max(S)-min(S)
    print(int(a/(N-2)))
