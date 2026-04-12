from collections import Counter

alpha = [float('inf')] * 26
n = int(input())

for _ in range(n):
    dic = Counter(list(input()))
    for i in range(26):
        if chr(i + 97) not in dic:
            alpha[i] = 0
        elif dic[chr(i + 97)] < alpha[i]:
            alpha[i] = dic[chr(i + 97)]

ans = ''
for i in range(26):
    ans += chr(i + 97) * alpha[i]

print(ans)