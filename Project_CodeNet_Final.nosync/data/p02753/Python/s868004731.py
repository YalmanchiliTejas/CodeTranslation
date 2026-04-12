x = input()
for i in [0,1,2]:
    j = (i+1)%3
    if not x[i] == x[j]:
        print('Yes')
        exit()
print('No')