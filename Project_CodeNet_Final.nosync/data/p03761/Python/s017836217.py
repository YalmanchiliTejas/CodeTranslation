N = int(input())
alpha = [chr(i) for i in range(97, 97+26)]
dic = {i:100 for i in alpha}
for _ in range(N):
    tmpdic = {i:0 for i in alpha}
    S = input()
    for s in S:
        tmpdic[s] += 1
    for i in alpha:
        if tmpdic[i] < dic[i]:
            dic[i] = tmpdic[i]
ans =[]
for i in alpha:
    for _ in range(dic[i]):
        ans.append(i)
print(''.join(ans))