# coding: utf-8
# Your code here!
N = int(input())
lst = list(map(int,input().split()))
low_mountain = lst[0]
count= 0
for i in lst:
    if i >= low_mountain:
        low_mountain = i
        count+=1
print(count)