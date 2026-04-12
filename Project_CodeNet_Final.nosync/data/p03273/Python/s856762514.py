h,w = map(int,input().split())
list1 = []
for i in range(h):
  list1.append(list(input()))

def del_rows(r):
  del list1[r]

def del_cols(c):
  for l in range(h):
    del list1[l][c]
i = 0
#colの削除
while True:
  flag = 1
  if i >= len(list1[0]):
    break
  for j in list1:
    if j[i] == "#":
      flag = 0
      break
  if flag:
    del_cols(i)
  else:
    i += 1
#rowの削除
i = 0
while True:
  if i >= len(list1):
    break
  if all(j == "." for j in list1[i]):
    del_rows(i)
  else:
    i += 1
for i in range(len(list1)):
  print("".join(list1[i]))