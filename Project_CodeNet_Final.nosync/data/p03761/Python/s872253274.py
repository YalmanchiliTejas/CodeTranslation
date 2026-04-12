from collections import Counter
n = int(input())
lists = list(input())
l = dict(Counter(lists))
for i in range(n-1):
  tmp_l = dict(Counter(list(input())))
  for key in l.keys():
    if key not in tmp_l.keys():
      l[key] = 0
    elif l[key] > tmp_l[key]:
      l[key] = tmp_l[key]

string = ""
for key in l:
  string += ''.join([key for _ in range(l[key])])
    
l = list(string)
l.sort()

string = ''.join(l)
print(string)