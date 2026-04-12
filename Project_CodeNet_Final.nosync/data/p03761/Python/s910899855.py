n = int(input())
s = []
for i in range(n):
    s.append(input())
jisyo = []

for moji in s:
    dic = {}
    for i in moji:
        if i not in dic:
            dic[i] = 1
        else:
            dic[i] +=1
    jisyo.append(dic)

moji = "abcdefghijklmnopqrstuvwxyz"
ansdic = {}
for i in range(len(moji)):
    ansdic[moji[i]] = 100
for tmpdic in jisyo:
    for i in range(len(moji)):
        if moji[i] not in tmpdic.keys():
            ansdic[moji[i]] = 0
        else:
            if tmpdic[moji[i]] < ansdic[moji[i]]:
                ansdic[moji[i]] = tmpdic[moji[i]]
ans = ""
for key,value in ansdic.items():
    if value != 0:
        ans +=key*value
print(ans)