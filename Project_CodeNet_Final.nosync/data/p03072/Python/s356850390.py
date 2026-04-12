n = (int,input())
li = list(map(int,input().split()))
max_height = 0
i = 0
count = 0
for i in li:
    if max_height <= i:
        count = count + 1
        max_height = i
    else:
        i = i+1
print(count)