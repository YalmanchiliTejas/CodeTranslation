n = int(input())
s = input()
k = int(input())
tmp = s[k - 1]
for i in range(n):
    if s[i] != tmp:
        s = s[:i] + "*" + s[i + 1:]
print(s)