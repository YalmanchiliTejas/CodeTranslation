import sys

a=input()
for i in range(len(a)-1):
  if a[i]=='A' and a[i+1]=='C':
    print("Yes")
    sys.exit()
print("No")