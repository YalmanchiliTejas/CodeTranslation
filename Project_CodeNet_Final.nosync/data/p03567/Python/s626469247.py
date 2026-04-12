S=input()
for i in range(1,len(S)):
  if "AC"==S[i-1]+S[i]:
    print("Yes")
    exit()
print("No")
