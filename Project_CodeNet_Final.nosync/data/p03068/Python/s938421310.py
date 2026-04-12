n=int(input())
s=list(input())
k=int(input())
s_k=s[k-1]
for i in range(n):
  if s[i]!=s_k:
    s[i]="*"
print("".join(s))