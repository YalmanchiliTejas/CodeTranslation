n = int(input())
s = input()
list_pat = [["S", "S"], ["S", "W"], ["W", "S"], ["W", "W"]]
for one_s in s[1:]:
  if one_s == "o":
    for i, one_pat in enumerate(list_pat):
      if one_pat[-1] == "S":
        if one_pat[-2] == "S":
          list_pat[i].append("S")
        else:
          list_pat[i].append("W")
      else:
        if one_pat[-2] == "S":
          list_pat[i].append("W")
        else:
          list_pat[i].append("S")
  else:
    for i, one_pat in enumerate(list_pat):
      if one_pat[-1] == "S":
        if one_pat[-2] == "S":
          list_pat[i].append("W")
        else:
          list_pat[i].append("S")
      else:
        if one_pat[-2] == "S":
          list_pat[i].append("S")
        else:
          list_pat[i].append("W")

for one_pat in list_pat:
  if one_pat[0] == one_pat[-1]:
    if one_pat[0] == "S":
      if s[0] == "o" and one_pat[-2] == one_pat[1]:
        print("".join(one_pat[:-1]))
        exit()
      elif s[0] == "x" and one_pat[-2] != one_pat[1]:
        print("".join(one_pat[:-1]))
        exit()
    else:
      if s[0] == "o" and one_pat[-2] != one_pat[1]:
        print("".join(one_pat[:-1]))
        exit()
      elif s[0] == "x" and one_pat[-2] == one_pat[1]:
        print("".join(one_pat[:-1]))
        exit()
print("-1")