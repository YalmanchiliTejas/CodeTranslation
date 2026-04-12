n = int(input())
s = list(input())
k = int(input())


for i in range(n):
    if s[i] != s[k-1] :
        s[i] = "*"

for i in s:
    print(i,end="")