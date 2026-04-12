n=int(input())
s=list(input())
k=int(input())
x=s[k-1]
for i in range(len(s)):
    if s[i]!=x:
        s[i]="*"

s="".join(s)
print(s)