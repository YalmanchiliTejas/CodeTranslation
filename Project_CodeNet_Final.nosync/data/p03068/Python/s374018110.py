n=int(input())
s=str(input())
k=int(input())
s=list(s)
for i in range(0,len(s)):
  if s[i]!=s[k-1]:
    s[i]="*"
print("".join(map(str, s)))