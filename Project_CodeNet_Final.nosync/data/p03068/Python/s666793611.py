n=int(input())
s=list(input())
k=int(input())
p=s[k-1]
for i in range(len(s)):
  if s[i]!=p:
    s[i]="*"
print("".join(s))