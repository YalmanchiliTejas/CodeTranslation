import sys
lst_st = list(input())

for i in range(2):
  if (lst_st[i] != lst_st[i+1]):
    print("Yes")
    sys.exit()
  else:
    continue
else:
  print("No")

    