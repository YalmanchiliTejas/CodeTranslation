# -*- coding: utf-8 -*-
n,x = list(map(int,input().split()))

#n=1~50までのパティの数と、バーガーの長さ
l = [(1,1)]
for i in range(1,51):
    l.append((l[-1][0]*2+1,l[-1][1]*2+3))

def calc(dim,eat):
    ret = 0
    if eat==0:
        return 0
    elif dim==0:
        return 1
    else:
        if eat < l[dim][0]:
            ret+=calc(dim-1,eat-1)
        elif eat==l[dim][1]:
            return l[dim][0]
        else:
            ret+=(l[dim-1][0]+1+calc(dim-1,eat-l[dim][0]))
    return ret

print(calc(n,x))