def resolve():
    N, X = list(map(int, input().split()))
    level_len = [1]
    for i in range(1, N+1):
        level_len.append(2*level_len[i-1]+3)
    #print(level_len)
    mem = {"0-0": 1}

    def get_cnt(level, pos):
        if "{}-{}".format(level, pos) in mem:
            return mem["{}-{}".format(level, pos)]

        result = None
        if pos == 0:
            result = 0
        elif 1 <= pos <= level_len[level-1]:
            result = get_cnt(level-1, pos-1)
        elif pos == 1+level_len[level-1]:
            result = get_cnt(level-1, level_len[level-1]-1)+1
        elif 1+level_len[level-1] < pos <= 1+2*level_len[level-1]:
            result = get_cnt(level-1, level_len[level-1]-1) + 1 + get_cnt(level-1, pos-level_len[level-1]-2)
        elif pos == 2*level_len[level-1]+2:
            result = 2*get_cnt(level-1, level_len[level-1]-1)+1

        if result is None:
            #print(level, pos)
            raise Exception("Invalid")
        mem.setdefault("{}-{}".format(level, pos), result)
        return result
    
    print(get_cnt(N, X-1))

    

if '__main__' == __name__:
    resolve()