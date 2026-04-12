def resolve():
    '''
    code here
    '''

    import collections
    N = int(input())
    S_list = [collections.Counter(input()) for _ in range(N)]

    cnt_dict = S_list[0]

    for line in S_list:
        for item in cnt_dict.keys():
            cnt_dict[item] = min(line[item], cnt_dict[item])
        prev_dict = cnt_dict
        # print(cnt_dict)
    
    cnt_tuple = sorted(cnt_dict.items())
    # print(cnt_tuple)
    res = ''
    for i, v in cnt_tuple:
        if v > 0:
            res += i*v

    print(res)

if __name__ == "__main__":
    resolve()    

