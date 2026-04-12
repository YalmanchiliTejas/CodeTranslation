N, *h = map(int, open(0).read().split()) 

max = 0
count = 0
for i in h:
    if (i >= max):
        count = count + 1
        max = i
print(count)
