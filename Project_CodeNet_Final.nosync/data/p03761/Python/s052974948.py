import collections
def main():
    n = int(input())
    s = []
    s_cnt = []
    len_min = 100
    min_idx = 0
    for i in range(n):
        ss = input()
        s.append(ss)
        cha = collections.Counter(list(ss))
        s_cnt.append(cha)
        if len_min > len(cha):

            len_min = min(len_min, len(cha))
            min_idx = i
    ans = []
    for i in range(97,97+26):
        alp = chr(i)
        tmp = [0] * n
        for j, cnt in enumerate(s_cnt):
            tmp[j] = cnt[alp]
        ans.append(min(tmp))
    ans_str = ''
    for i, num in enumerate(ans, 97):
        if num != 0:
            for j in range(num):
                ans_str += chr(i)
    print(ans_str)



if __name__ == '__main__':
    main()
