# -*- Coding: utf-8 -*-

trial_num = int(input())
n_line = [0 for i in range(trial_num)]

alphabet = [chr(i) for i in range(ord('a'), ord('z')+1)]

for i in range(trial_num):
    n_line[i] = list(input())


result_list = [0 for i in range(26)]
tmp = 50

for i in range(26):
    for j in range(trial_num):
        tmp_min = n_line[j].count(alphabet[i])
        if(tmp_min < tmp):
            tmp = tmp_min

    result_list[i] = tmp
    tmp = 50

for i in range(26):
    print(result_list[i] * alphabet[i], end = "")