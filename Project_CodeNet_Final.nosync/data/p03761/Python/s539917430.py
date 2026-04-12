# -*- coding: utf-8 -*-
N = int(input())
Sn = []
for _ in range(N):
    Sn.append(list(input()))

Sn_ccnt = [{} for _ in range(N)]

for i,Si in enumerate(Sn):
    for c in Si:
        if c in Sn_ccnt[i]:
            Sn_ccnt[i][c] += 1
        else:
            Sn_ccnt[i][c] = 1

char_cnt = {}
for c in 'abcdefghijklmnopqrstuvwxyz':
    for ccnt in Sn_ccnt:
        if c in ccnt:
            if c in char_cnt:
                if ccnt[c] < char_cnt[c]:
                    char_cnt[c] = ccnt[c]
            else:
                char_cnt[c] = ccnt[c]
        else:
            char_cnt[c] = 0

ans = ""
for k, v in sorted(char_cnt.items(), key=lambda x: x[0]):
    ans += k*v

# print(char_cnt)
print(ans)
