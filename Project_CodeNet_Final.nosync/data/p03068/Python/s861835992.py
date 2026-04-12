n=int(input())
s=list(input())
S=s[int(input())-1]
for i in range(n):
    if s[i]!=S:
        s[i]="*"
print("".join(s))