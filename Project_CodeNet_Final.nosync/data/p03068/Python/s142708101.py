n = input()
s = input()
n = int(input())
for i in s:
  if i==s[n-1] :
    print(i,end="")
  else:
    print("*",end="")
print()