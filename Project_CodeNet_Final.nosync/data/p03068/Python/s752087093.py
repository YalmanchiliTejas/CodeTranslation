n = int(input())
s = list(str(input()))
k = int(input())

key = s[k-1]
for i in range(n):
    if s[i] != key:
        s[i] = "*"
s = "".join(s)
print(s)