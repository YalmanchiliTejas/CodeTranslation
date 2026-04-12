# encoding: utf-8
n = int(input())
S = [input() for i in range(n)]

table = [[0] * n for i in range(26)]
base = ord("a")

for i, Si in enumerate(S):
    for char in Si:
        table[ord(char) - base][i] += 1

ans = ""
for i, row in enumerate(table):
    if min(row) >= 1:
        for j in range(min(row)): ans += chr(base + i)

print(ans)