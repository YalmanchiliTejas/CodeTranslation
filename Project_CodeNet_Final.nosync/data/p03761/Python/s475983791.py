from collections import Counter
n = int(input())
s = [Counter(input()) for i in range(n)]
ans = ""
for i in s[0].keys():
    ans += i*min([s[j][i] for j in range(len(s))])
print("".join(sorted(ans)))