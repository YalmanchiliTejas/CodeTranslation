# coding:utf-8
import math

line_list = input().split(" ")

x = int(line_list[0])
y = int(line_list[1])
z = int(line_list[2])

print(int(math.floor((x-z)/(y+z))))
