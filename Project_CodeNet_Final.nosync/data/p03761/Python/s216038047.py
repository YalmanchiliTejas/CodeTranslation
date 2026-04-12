import collections
n = int(input())
dic = {}
for i in range(n):
    S = input()
    S_col = collections.Counter(S)
    if  i == 0:
        dic = S_col
    else:
        for key,val in dic.items():
            if key in S_col:
                dic[key] = min(dic[key],S_col[key])
            else:
                dic[key] = 0
s = ''
for key,val in dic.items():
    s += key*val
print(''.join(sorted(s)))