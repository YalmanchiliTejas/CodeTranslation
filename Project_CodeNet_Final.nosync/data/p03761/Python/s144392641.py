# -*- coding: utf-8 -*-

n = input()
S = ['']*n
common = []
#読み込み
for i in range(n):
    S[i] = raw_input()
    
#共通文字の抽出
common = list(S[0])
for k in range(1,n):
    deletelist = []
    for i in range(len(common)):
        findchar = S[k].find(common[i])
        if(findchar != -1):
            S[k] = S[k].replace(common[i],'A',1)
        else:
            deletelist.append(i)
    for j in deletelist[::-1]:
        common.pop(j)
    
sortedcommon = sorted(common)
print ''.join(sortedcommon)