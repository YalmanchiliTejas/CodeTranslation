n = int(input())
sl = list(input())
k = int(input())

ans = []
for s in sl:
   if s == sl[k-1]:
      ans.append(s)
   else:
      ans.append("*")
   
print("".join(ans))