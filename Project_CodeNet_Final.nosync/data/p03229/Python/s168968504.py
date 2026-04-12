def resolve():
    '''
    code here
    '''
    import collections
    N = int(input())
    A_list = [int(input()) for _ in range(N)]
    A_odered = collections.deque(sorted(A_list))
    res_list = collections.deque([A_odered.popleft()])
    res_list.appendleft(A_odered.pop())
    res = abs(res_list[0] - res_list[1])

    while len(A_odered) >= 1:
        temp_def1 = abs(res_list[0] - A_odered[-1])
        temp_def2 = abs(res_list[-1] - A_odered[-1])
        temp_def3 = abs(res_list[0] - A_odered[0])
        temp_def4 = abs(res_list[-1] - A_odered[0])

        max_deff = max(temp_def1, temp_def2, temp_def3, temp_def4)
        if temp_def1 == max_deff:
            res += temp_def1
            res_list.appendleft(A_odered.pop())
        elif temp_def2 == max_deff:

            res += temp_def2
            res_list.append(A_odered.pop())
        elif temp_def3 == max_deff:
            res += temp_def3
            res_list.appendleft(A_odered.popleft())
        else:
            res += temp_def4
            res_list.append(A_odered.popleft())
    # print(res_list)
    print(res)
if __name__ == "__main__":
    resolve()
