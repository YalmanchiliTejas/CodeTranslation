#coding: utf-8

num = int(input())
columns = list(map(int, input().rstrip().split(' ')))
count = num
x = num
for h in columns:
    
    for i in columns[0:-x]:
        
        if h < i:
            count -= 1
            break
    x -= 1
print(count)			