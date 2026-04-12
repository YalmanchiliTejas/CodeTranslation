def common_str(n,listt):
    ans_list = []
    flag = True

    while flag:
        com = set(listt[0])
        for i in range(1,n):
            com &= set(listt[i])
        a = list(com)
        if len(a) != 0:
            for i in range(len(com)):
                ans_list.append(list(com)[i])
                for j in range(n):
                    listt[j].remove(list(com)[i])
        else:
            flag = False

    return ans_list

if __name__ == '__main__':
    n = int(input())
    listt = []
    for i in range(n):
        x = list(input())
        listt.append(x)

    tmp = common_str(n,listt)
    tmp.sort()
    print(''.join(tmp))
