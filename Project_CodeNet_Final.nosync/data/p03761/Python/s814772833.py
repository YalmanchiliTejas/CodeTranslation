from copy import deepcopy
n = int(input())
S = [input() for i in range(n)]
dict_count = {}
for i in range(26):
    dict_count[97+i] = 0
def values_return(string):
    copy = deepcopy(dict_count)
    for e in string:
        copy[ord(e)] += 1
    return list(copy.values())
S_count = [values_return(e) for e in S]
common = []
for j in range(26):
    min_count = 51
    for i in range(len(S_count)):
        if S_count[i][j] < min_count:
            min_count = S_count[i][j]
    common.append(min_count)
ans = ""
for i in range(26):
    ans += chr(97+i) * common[i]
print(ans)