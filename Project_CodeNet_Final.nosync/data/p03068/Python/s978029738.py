n=int(input())
s=input()
k=int(input())
d=s[k-1]
s_list=list(s)
for a in range(n):
  if s[a] != d:
    s_list[a]="*"
s2="".join(s_list)
print(s2)