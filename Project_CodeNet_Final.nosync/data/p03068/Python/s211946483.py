n = int(input())
s = list(input())
k = int(input())
c = s[k-1]

for i in range(n):
    if s[i] != c:
        s[i] = "*"

for i in s:
    print(i,end="")
print()