n=int(input())
s=list(input())
k=s[int(input())-1]
for i in range(n):
    if s[i]!=k:
        s[i]="*"
print(*s,sep="")