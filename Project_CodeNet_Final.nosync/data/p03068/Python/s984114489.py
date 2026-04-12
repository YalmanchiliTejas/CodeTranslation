n = int(input())
s = list(map(str,input()))
k = int(input())

a = s[k-1]

for i in range(n):
    if s[i]==a:
        continue
    else:
        s[i] = "*"

print("".join(s))