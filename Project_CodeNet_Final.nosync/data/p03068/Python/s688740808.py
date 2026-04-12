n=int(input())
s=list(input())
k=int(input())
m=s[k-1]
for i,ss in enumerate(s):
  if ss!=m:
    s[i]="*"
print("".join(s))
