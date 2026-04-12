num = list(map(int,raw_input().split()))
point = num[0]
line = num[1]
total = 0
d = {}
for i in range (point):
    d[i+1] = []
for i in range(line):
    pair = list(map(int,raw_input().split()))
    d[pair[0]].append(pair[1])
    d[pair[1]].append(pair[0])
old_list = []
new_list = [[1]]
for i in range (point-1):
    old_list = new_list[:]
    new_list =[]
    for j in old_list:
        for k in d[j[-1]]:
            if k in j:
                pass
            else:
                j.append(k)
                new_list.append(j[:])
                j.pop()
print len (new_list)
