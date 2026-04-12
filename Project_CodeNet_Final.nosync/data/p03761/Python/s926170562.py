ls = "abcdefghijklmnopqrstuvwxyz"
n = int(input())
rr = [[0 for _ in range(26)]for i in range(n)]
for i in range(n):
    s = list(input())
    for j in range(len(s)):
        rr[i][ls.index(s[j])] += 1
for i in range(26):
    for j in range(min(list(map(lambda x:x[i] ,rr)))):
        print(ls[i],end="")
print()