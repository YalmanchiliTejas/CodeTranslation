n = int(input())
S = [input() for i in range(n)]
Chars = [[0 for i in range(n)] for i in range(26)]

for i in range(n):
    for s in S[i]:
        Chars[ord(s)-97][i] += 1

Chars_min = list(map(min,Chars))

ans = ''
for i in range(26):
    ans += chr(i+97)*Chars_min[i]

print(ans)