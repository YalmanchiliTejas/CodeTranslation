from collections import OrderedDict
n = int(input())
s_list = list()
for i in range(n):
    s_list.append(input())

dictionary_list = list()
    
for s in s_list:
    dictionary = dict()
    for w in s:
        if w in dictionary:
            dictionary[w] += 1
        else:
            dictionary[w] = 1
    dictionary_list.append(dictionary)

first = dictionary_list[0]
pop_list = list()

for key,value in first.items():
    for dictionary in dictionary_list[1:]:
        if key in dictionary:
            first[key] = min(first[key],dictionary[key])
        else:
            pop_list.append(key)

for p in pop_list:
    if p in first:
        first.pop(p)
          
first = OrderedDict(sorted(first.items(),key=lambda x: x[0]))
t = ""
for k,v in first.items():
    t += k*v
print(t)