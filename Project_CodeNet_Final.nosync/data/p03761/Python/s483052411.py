from collections import Counter

N = int(input())
S = [Counter(input()) for _ in range(N)]

INF = 55
memo = [INF] * 26
for s in S:
    for i in range(26):
        memo[i] = min(memo[i], s[chr(ord('a') + i)])

print("".join(chr(ord('a') + i) * memo[i] for i in range(26)))