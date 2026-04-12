n = int(input())
S = []
for _ in range(n):
    S.append(input())

def word2dic(word):
    dic = {}
    for c in word:
        if c in dic:
            dic[c] += 1
        else:
            dic[c] = 1
    return dic

def dp(dic, dic_add):
    for key in dic_add.keys():
        if key in dic:
            dic[key] = min(dic[key], dic_add[key])
    dic_keys = list(dic.keys())
    for key in dic_keys:
        if not key in dic_add:
            del dic[key]
    return dic

dic = word2dic(S[0])
for s in S[1:]:
    dic = dp(dic, word2dic(s))
    
result = ''
for key in sorted(dic.keys()):
    for _ in range(dic[key]):
        result += key
print(result)