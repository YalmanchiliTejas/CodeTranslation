S = input()


dic_ = {"A":0, "B":0}
for s in S:
  dic_[s] += 1

if dic_["A"] == 0 or dic_["B"] == 0:
  print("No")
else:
  print("Yes")
    
  