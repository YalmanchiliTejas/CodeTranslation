import sys
from collections import deque
import copy
import heapq
import math

from math import *

def get_read_func(fileobject):
    if fileobject == None :
        return raw_input
    else:
        return fileobject.readline


count = 0

def dfs(N, adj_list, nd, visit_num, is_visit):
    global count
    is_visit[nd] = True
    if visit_num == N:
        count += 1
    for adj in adj_list[nd]:
        if is_visit[adj] == False:
            dfs(N, adj_list, adj, visit_num + 1, is_visit)
            is_visit[adj] = False


def main():
    global count
    if len(sys.argv) > 1:
        f = open(sys.argv[1])
    else:
        f = None
    read_func = get_read_func(f);
    input_raw = read_func().strip().split()
    [N, M] = [long(input_raw[0]), long(input_raw[1])]
    adj_list = {}
    for i in range(M):
        input_raw = read_func().strip().split()
        [a, b] = [long(input_raw[0]), long(input_raw[1])]
        if a not in adj_list:
            adj_list[a] = [b]
        else:
            adj_list[a].append(b)

        if b not in adj_list:
            adj_list[b] = [a]
        else:
            adj_list[b].append(a)
    is_visit = [False for i in range(N + 1)]

    dfs(N, adj_list, 1, 1, is_visit)

    print count






if __name__ == '__main__':
    main()
