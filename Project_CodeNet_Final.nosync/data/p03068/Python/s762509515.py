n = int(input())
s = list(input())
k = int(input()) - 1

for i in range(n):
    if s[i] != s[k]:
        s[i] = "*"
        
print(*s,sep="")