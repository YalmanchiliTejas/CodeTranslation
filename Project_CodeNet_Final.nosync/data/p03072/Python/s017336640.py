# coding: utf-8
n = int(input())

high = list(map(int, input().split()))
max_high = []
count =1

for i in range(1,n):
    x = high[:i]
    if(max(x) <= high[i]):
        count = count +1
        
print(count)