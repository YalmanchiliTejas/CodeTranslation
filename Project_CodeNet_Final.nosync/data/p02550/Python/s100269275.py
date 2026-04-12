def resolve():
    N, X, M = map(int,input().split())
    A_list = [X]
    preA = X
    A_set = set(A_list)
    for i in range(N-1):
        A = preA**2%M

        if A == 0:
            answer = sum(A_list)
            break
        elif A in A_set:
            finished_count = len(A_list)
            # 何番目か確認
            same_A_index = A_list.index(A)
            one_loop = A_list[same_A_index:]
            loop_count, part_loop = divmod(N-finished_count, len(one_loop))
            answer = sum(A_list) + sum(one_loop)*loop_count + sum(one_loop[:part_loop])
            break

        A_list.append(A)
        A_set.add(A)
        preA = A
    else:
        answer = sum(A_list)
    print(answer)
resolve()