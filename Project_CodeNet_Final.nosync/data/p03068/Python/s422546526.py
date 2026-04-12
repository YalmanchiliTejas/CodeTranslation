n=int(input())
s=list(input())
k=int(input())
char=s[k-1]
for i in range(n):
    if s[i]!=char:
        s[i]="*"
print("".join(s))