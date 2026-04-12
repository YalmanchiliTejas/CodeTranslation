from collections import Counter

N = int(input())
S = [Counter(input()) for _ in range(N)]

INF = 55
memo = [INF] * 26
for s in S:
    for i in range(26):
        memo[i] = min(memo[i], s[chr(ord('a') + i)])

result = ""
for i in range(26):
    if memo[i] != 0:
        result += chr(ord('a') + i) * memo[i]

print(result)