h,w = map(int, input().split())
list_prob = []
for i in range(0,h):
    list_prob.append(list(str(input())))
i = 0
while i < h:
    #print(i)
    if list_prob[i].count("#") == 0:
        del list_prob[i]
        h -= 1
        i -= 1
    i += 1
    #print(list_prob)

#print(list_prob)
j = 0
while j < w:
    list_j = []
    for i in range(0,h):
        list_j.append(list_prob[i][j])
    if list_j.count("#") == 0:
        for i in range(0,h):
            del list_prob[i][j]
        w -= 1
        j -= 1
    j += 1

for row in list_prob:
    print("".join(row))
