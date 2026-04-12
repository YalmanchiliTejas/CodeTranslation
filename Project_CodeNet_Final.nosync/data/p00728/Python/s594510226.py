while True:
    N = int(input())
    if N == 0:
        break
    S = []
    for _ in range(N):
        S.append(int(input()))
    S.sort()
    S = S[1:N-1]
    ans = sum(S)//len(S)
    print(ans)
