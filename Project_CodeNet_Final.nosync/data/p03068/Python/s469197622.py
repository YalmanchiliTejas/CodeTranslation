n=int(input())
s=list(input())
k=int(input())
key=s[k-1]
for i, si in enumerate(s):
    if si != key:
        s[i]="*"
print(*s,sep="")
