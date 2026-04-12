s=input()
for i,j in zip(s[:-1],s[1:]):
  if i+j=="AC":
    print("Yes")
    exit()
print("No")