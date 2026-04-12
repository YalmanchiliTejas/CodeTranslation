n = int(input())
s = input()
k = int(input())

t = list(s)
for i in range(n):
    if t[i] != t[k-1]:
        t[i] = "*"

for i in range(n):
    print(t[i], end="")