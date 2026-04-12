#!/usr/bin/env python3
n = int(input())
s = [input() for _ in range(n)]
cnt = [50]*26 #a~z の出現回数　のmin INFしょきか
for i in range(n):
    tmp = [0]*26
    for c in s[i]:
        tmp[ord(c)-97] += 1
    for j in range(26):
        cnt[j] = min(cnt[j],tmp[j])
#出力は辞書順最小
for c in range(26):
    print(chr(97+c)*cnt[c],end="")