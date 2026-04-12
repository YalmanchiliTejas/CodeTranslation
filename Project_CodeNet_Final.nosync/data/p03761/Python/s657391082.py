n = int(input())
S = [input() for _ in range(n)]
h = [[0]*26 for _ in range(n)]
for i in range(n):
    for c in S[i]:
        h[i][ord(c)-ord('a')] += 1
print(''.join([chr(i+ord('a'))*min([h[j][i] for j in range(n)]) for i in range(26)]))
