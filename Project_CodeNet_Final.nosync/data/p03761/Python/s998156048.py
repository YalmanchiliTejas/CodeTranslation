n = int(input())
t = [[0 for _ in range(26)] for _ in range(n)]
for i in range(n):
    s = input()
    for j in range(len(s)):
        t[i][ord(s[j])-97] += 1
ans = [0 for _ in range(26)]
for i in range(26):
    min_c = 50
    for j in range(n):
        min_c = min(min_c, t[j][i])
    ans[i] = min_c

s = ""
for i in range(26):
    for j in range(ans[i]):
        s += chr(97+i)

print(s)