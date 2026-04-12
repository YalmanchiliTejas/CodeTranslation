from collections import defaultdict


n = int(input())

dic = [defaultdict(lambda: 0) for i in range(n)]

keys = [None]*n

for i in range(n):
    s = input()
    for j in range(len(s)):
        dic[i][s[j]] += 1

    keys[i] = set(dic[i])

key = keys[0]

for i in range(1,n):
    key = key & keys[i]

key = list(key)
key.sort()
nums = [0]*len(key)
ans = ""

for j in range(len(key)):
    tmp = [0]*n
    for i in range(n):
        tmp[i] = dic[i][key[j]]
    nums[j] = min(tmp)
    ans += key[j]*nums[j]
print(ans)
