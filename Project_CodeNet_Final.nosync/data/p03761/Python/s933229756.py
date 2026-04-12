alpha = "abcdefghijklmnopqrstuvwxyz"
from collections import Counter
n = int(input())
alp_max = [10**3] * 26
for i in range(n):
    C = Counter(input())
    for j in range(26):
        alp_max[j] = min(alp_max[j], C[alpha[j]])
ans = ""
for i in range(26):
    ans += alpha[i] * alp_max[i]
print(ans)
