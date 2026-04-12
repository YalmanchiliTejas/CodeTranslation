vals = input().split()
s_val = ""
for v in vals:
  s_val = s_val + v
 
i_val = int(s_val)

if i_val%4==0:
  print("YES")
else:
  print("NO")
