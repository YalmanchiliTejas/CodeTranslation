#coding:utf-8
ls_len = [1]
ls_p = [1]
for i in range(50):
    ls_len.append(2*ls_len[-1]+3)
    ls_p.append(1+2*ls_p[-1])
n,x = map(int,input().split())

def calc_p(level,x):
    if level == 0:
        return 1
    elif x == ls_len[level]-1:
        return ls_p[level]
    elif x == 0:
        return 0
    elif x == (ls_len[level]-1)/2:
        return ls_p[level-1]+1
    elif x < (ls_len[level]-1)/2:
        return calc_p(level-1,x-1)
    else:
        return calc_p(level-1,x-2-ls_len[level-1])+ls_p[level-1]+1
print (calc_p(n,x-1))