n=int(input())
s=input()
k=int(input())
j=s[k-1]
new_s=""
for i in range(n):
  if s[i]!=j:
    new_s+="*"
  else:
    new_s+=j
print(new_s)