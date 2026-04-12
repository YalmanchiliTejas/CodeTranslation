from math import *

while True:
    a = int(input())
    if a == 0: break

    #print('a')
    score_list = []
    #max_score = 0
    #min_score = 1000
    for i in range(a):
        score_list.append(int(input()))
    #print(score_list)
    max_ = max(score_list)
    min_ = min(score_list)

    #print('b')
    ans_list = []
    flag = 0
    for score in score_list:
        if score == max_ and not flag:
            flag = 1
            continue
        else:
            ans_list.append(score)

    new_ans_list = []
    flag = 0
    for score in ans_list:
        if score == min_ and not flag:
            flag = 1
            continue
        else:
            new_ans_list.append(score)

    avg = sum(new_ans_list)/len(new_ans_list)
    print(int(avg))

