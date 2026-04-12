# -*- coding: utf-8 -*-
import sys


N,M=[int(i) for i in input().rstrip().split()]
ab_list=[[int(j) for j in input().split()] for i in range(M)]
#-----

vertex_dic={}  # dic{int:set()}

for va,vb in ab_list:
    vertex_dic.setdefault(va,set())
    vertex_dic[va].add(vb)
    vertex_dic.setdefault(vb,set())
    vertex_dic[vb].add(va)


def check(vertex_dic :dict, passed :set, start :int):
    if len(vertex_dic) == len(passed):
        return 1
    
    next_set = vertex_dic[start] - passed # :set
    
    ans=0
    for i_next in next_set:
        next_passed = passed | {i_next}
        ans += check(vertex_dic, next_passed, i_next)
    
    return ans
    

result=check(vertex_dic, {1}, 1 )
print(result)
