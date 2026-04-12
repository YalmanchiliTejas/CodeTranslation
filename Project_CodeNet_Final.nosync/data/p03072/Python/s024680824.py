n = int(input())
mountains = list(map(int,input().split(' ')))
maxMount = mountains[0]
count = 0
for height in mountains:
    if maxMount <= height:
        count += 1
        maxMount = height
print(count)
