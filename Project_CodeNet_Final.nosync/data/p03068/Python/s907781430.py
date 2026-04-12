n = int(input())
s = list(str(input()))
k = int(input())

c = s[k-1]

for i in range(0,n):
    if s[i] != c:
        s[i] = "*"

for j in s:
    print(j,end = "")