N  = int (input())
As = [int(input()) for _ in range(N)]
# print(As)
As.sort()
if N == 1:
    print(0)

#小さい方から配置

elif N == 2:
    print(abs(As[0] - As[1]))
else:
    bottom_ind = 1
    upper_ind = N - 1

    l = r = As[0]

    MA = 1
    MI = 0
    mode = MA

    ans1 = 0
    while True:
        if mode == MA: #上から取る
            next1 = As[upper_ind]
            next2 = As[upper_ind -1]
            ans1 += max(abs(next1 - l ) + abs(next2 - r ),abs(next2 - r ) + abs(next1 - l ))
            r =  next1
            l = next2
            m = upper_ind  - 2
            upper_ind -= 2
            mode = MI

        else:
            next1 = As[bottom_ind]
            next2 = As[bottom_ind + 1]
            ans1 += max(abs(next1 - l) + abs(next2 - r), abs(next2 - r) + abs(next1 - l))
            m = bottom_ind + 2
            bottom_ind+= 2
            r = next1
            l = next2
            mode = MA #下から取る
        if bottom_ind >= upper_ind:
            break
    if N % 2 == 0:
        # m = As[N//2]
        m = As[m]
        ans1 += max( abs(m - l) ,abs(m - r))


    #大きい方から配置

    bottom_ind = 0
    upper_ind = N - 2

    l = r = As[N - 1]


    mode = MI

    ans2 = 0
    while True:
        if mode == MA: #上から取る
            next1 = As[upper_ind]
            next2 = As[upper_ind -1]
            ans2 += max(abs(next1 - l ) + abs(next2 - r ),abs(next2 - r ) + abs(next1 - l ))
            r =  next1
            l = next2
            m = upper_ind  - 2
            upper_ind -= 2
            mode = MI

        else:
            next1 = As[bottom_ind]
            next2 = As[bottom_ind + 1]
            ans2 += max(abs(next1 - l) + abs(next2 - r), abs(next2 - r) + abs(next1 - l))
            m = bottom_ind + 2
            bottom_ind+= 2
            r = next1
            l = next2
            mode = MA #下から取る
        if bottom_ind >= upper_ind:
            break
    if N % 2 == 0:
        # m = As[N//2]
        m = As[m]
        ans2 += max( abs(m - l) ,abs(m - r))





    print(max(ans1,ans2))