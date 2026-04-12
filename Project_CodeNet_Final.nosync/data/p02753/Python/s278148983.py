S=list(input())
if all(s=="B" for s in S):
  print("No")
elif all(s=="A" for s in S):
  print("No")
else:
  print("Yes")