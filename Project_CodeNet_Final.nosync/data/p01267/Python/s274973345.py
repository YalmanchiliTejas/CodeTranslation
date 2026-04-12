while True:
    N, A, B, C, X = map(int, input().split())
    if N == 0 and A == 0 and B == 0 and C == 0 and X == 0:
        break
    Y = list(map(int, input().split()))

    done_frame = -1
    cur_reel = 0
    cur_X = X

    for i in range(10001):
        if cur_X == Y[cur_reel]:
            if cur_reel == N - 1:
                done_frame = i
                break
            else:
                cur_reel += 1
        cur_X = (A * cur_X + B) % C

    if done_frame >= 0:
        print(done_frame)
    else:
        print(-1)




