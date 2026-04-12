# coding: utf-8
# Your code here!


N = int(input())

input_list = input().split()

base = 0
count = 0

for i in input_list:
    num = int(i)

    if base <= num:
        count += 1
        base = num

print(count)

