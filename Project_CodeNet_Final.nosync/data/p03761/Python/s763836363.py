# -*- coding: utf-8 -*-

n = int(input())
S = [ input() for i in range(n) ]

chrs = {}
for i in range(n):
    tmp_chrs = {}
    for j in range(len(S[i])):
        tmp_chrs[S[i][j]] = tmp_chrs[S[i][j]] + 1 if S[i][j] in tmp_chrs else 1

    if i == 0:
        chrs = tmp_chrs
    else:
        new_chrs = {}
        for c in chrs:
            if c in tmp_chrs:
                new_chrs[c] = tmp_chrs[c] if tmp_chrs[c] < chrs[c] else chrs[c]
        chrs = new_chrs

if len(chrs) == 0:
    print('')
else:
    string = [ c * chrs[c] for c in chrs ]
    string.sort()
    print(''.join(string))