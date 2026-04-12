s = input()

a = s[0]
for i in range(1, 3) :
  if(s[i] != a) :
    print("Yes")
    exit()
print("No")