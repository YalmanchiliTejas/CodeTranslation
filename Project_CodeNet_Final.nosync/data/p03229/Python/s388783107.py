#coding:utf-8

N = int(input())
ls = []
for n in range(N):
    ls.append(int(input()))
ls.sort()
rm = []
temp = ls.pop(0)
rm.append(temp)
temp = ls.pop(-1)
rm.append(temp)
ans = rm[-1]-rm[0]
while(1):
    if len(ls)==0:
        break
    mx = 0
    for rm_index in range(2):
        for ls_index in [0,-1]:
            dist = abs(rm[rm_index]-ls[ls_index])
            if dist >= mx:
                mx = dist
                arg_rm = rm_index
                arg_ls = ls_index
    ans += mx
    rm[arg_rm] = ls.pop(arg_ls)
    #print(rm,ls)
print (ans)
