array = []
del_list = []

h,w = map(int, input().split())
for i in range(h):
  x = input()
  if "#" in x:
    y = list(x)
    array.append(y)
for i in range(w):
  for j in range(len(array)):
    if array[j][i] == "#":
      break
    else:
      if j == len(array)-1:
        del_list.append(i)
final_del_list = del_list[::-1]
for i in final_del_list:
  for j in range(len(array)):
    del array[j][i]
for i in range(len(array)):
    z = "".join(array[i])
    print(z)