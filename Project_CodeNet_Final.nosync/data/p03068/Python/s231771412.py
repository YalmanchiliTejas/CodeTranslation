n=int(input())
s=input()
k=int(input())
S=s[k-1]

for i in range(n):
  if s[i] != S:
    s=s.replace(s[i],"*")
print(s)