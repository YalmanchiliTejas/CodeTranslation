
N, X, M = map(int,input().split())

ans_list = [X]
if N == 1:
    print(X)
else:
    for i in range(1,N):
        ans = ans_list[-1]**2%M
        if ans in ans_list:
            break
        else:
            ans_list.append(ans)

    st_index = ans_list.index(ans)

    if st_index == N-1:
        print(sum(ans_list))
    else:
        total = sum(ans_list[:st_index])
        N -= st_index
        syo = N//(i-st_index)
        mod = N%(i-st_index)

        total += sum(ans_list[st_index:])*syo
        total += sum(ans_list[st_index:st_index+mod])
        print(total)