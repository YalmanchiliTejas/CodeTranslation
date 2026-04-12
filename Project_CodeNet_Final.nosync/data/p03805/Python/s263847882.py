import itertools
import copy

n, m = map(int, input().split())
List = [list(map(int, input().split())) for i in range(m)]
check = [0 for _ in range(n)]
res = 0

def all_1(res_list):
    leng = len(res_list)
    for i in range(leng):
        if res_list[i] == 0:
            return False
    return True

def coo(i, check):
    global res
    b = copy.deepcopy(check)
    if b[i-1] == 0:
        b[i-1] = 1
        if all_1(b):
            res += 1
        length = len(List)
        for j in range(length):
            if List[j][0] == i:
                coo(List[j][1], b)
        for j in range(length):
            if List[j][1] == i:
                coo(List[j][0], b)
        
        
coo(1, check)
print(res)