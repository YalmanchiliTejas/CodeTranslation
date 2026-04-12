n = int(input())
s = list(input())
k = int(input())

str = s[k-1]
for i in range(n):
    if s[i] != str:
        s[i] = "*"
    print(s[i],end="")