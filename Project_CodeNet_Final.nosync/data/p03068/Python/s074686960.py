n=int(input())
s=list(input())
k=int(input())
num=s[k-1]
num=str(num)
for i in range (0,n):
  if s[i]!=num:
    s[i]="*"
s=''.join(s)
print(s)