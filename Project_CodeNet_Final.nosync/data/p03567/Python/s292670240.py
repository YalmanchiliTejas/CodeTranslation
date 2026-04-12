s = input()
for i in range(len(s)):
  if s[i]=="A":
    for j in reversed(range(i,len(s))):
      if s[j] == "C":
        if j==i+1:
          print("Yes")
          exit()
print("No")
