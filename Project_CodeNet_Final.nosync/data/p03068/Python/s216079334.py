n = int(input())
s = input()
k = int(input())
ch = s[k-1]
for i in range(n):
    if s[i] != ch and s[i] != "*":
        s = s.replace(s[i], "*")
print(s)