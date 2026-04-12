from collections import Counter

n=int(input())
S=[Counter(input()) for i in range(n)]

ANS=""

for i in range(26):
    COUNT=min([S[j][chr(i+97)] for j in range(n)])
    ANS+=COUNT*chr(i+97)

print(ANS)