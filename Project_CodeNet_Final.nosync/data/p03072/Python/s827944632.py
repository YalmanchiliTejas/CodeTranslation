def resolve():
    N = int(input())
    H = list(map(int, input().split()))
    cnt = 0
    maxh = 0
    for i in range(N):
        if maxh <= H[i]:
            cnt += 1
            maxh = H[i]
    print(cnt)

if '__main__' == __name__:
    resolve()