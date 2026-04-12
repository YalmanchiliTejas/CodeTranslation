#coding:utf-8
n = input()
Ss = []
Scount = []
for i in xrange(n):
    S = raw_input()
    Ss.append(list(S))
    Scount.append(len(S))

#最小文字数のインデックスは？
min_index = Scount.index(min(Scount))
s = Ss[min_index]
Ss.pop(min_index)

memo = []


s = list(s)

for i in xrange(len(s)):
    check = []
    for j in xrange(len(Ss)):
        if s[i] in Ss[j]:
            check.append(str(1))
        else:
            check.append(str(-1))
    if "-1" in check:
        continue
    else:
        memo.append(s[i])
        for k in xrange(len(Ss)):
            Ss[k].pop(Ss[k].index(s[i]))

memo.sort()

answer = ""
for i in xrange(len(memo)):
    answer += memo[i]

print answer
