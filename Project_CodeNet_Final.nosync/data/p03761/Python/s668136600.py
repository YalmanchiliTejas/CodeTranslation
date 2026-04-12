# -*- coding: utf-8 -*-

n = int(input().strip())
S_list = [input().strip() for _ in range(n)]
#-----

share_s=set(S_list[0])
for s in S_list[1:]:
   share_s = share_s & set(s)

cnt_share_word={ w:50 for w in share_s}
for s in S_list:
    for word in share_s:
        cnt_share_word[word] = min(cnt_share_word[word], s.count(word))

ans=""
for k,i in cnt_share_word.items():
    ans += k*i

print(*sorted(ans),sep="")
