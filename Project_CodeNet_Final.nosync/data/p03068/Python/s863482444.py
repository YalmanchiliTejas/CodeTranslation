n = int(input())
k = input()
l = int(input())
m = k[l-1]
list = []
for i in range(len(k)):
  if k[i] == m:
    list.append(m)
  else:
    list.append("*") 
print(''.join(list))