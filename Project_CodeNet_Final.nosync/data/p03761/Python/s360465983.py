import string
from collections import Counter

ans = []
dic = {}

for a in string.ascii_lowercase:
    dic[a] = 51

N = int(input())
for _ in range(N):
    S = Counter(input())
    
    for l, c in dic.items():
        if dic[l] > S[l]:
            dic[l] = S[l]

for k, v in dic.items():
    if v != 0:
        ans.append(k * v)

ans.sort()
print("".join(map(str, ans)))