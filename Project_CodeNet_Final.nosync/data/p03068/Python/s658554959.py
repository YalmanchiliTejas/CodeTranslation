n=int(input())
s=list(input())
k=int(input())
tmp = s[k-1]
res = ["0"]*n
for i in range(n):
    if s[i] != tmp:
        res[i] = "*"
    else:
        res[i] = tmp
print(*res, sep="")