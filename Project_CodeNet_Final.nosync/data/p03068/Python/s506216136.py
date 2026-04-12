n = int(input())
s = input()
k = int(input())
t = ""
for i in range(n):
    if s[i] != s[k-1]:
        t += '*'
    else:
        t += s[i]
print(t)