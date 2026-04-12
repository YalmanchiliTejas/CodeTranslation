# coding: utf-8
# Your code here!

n = int(input())
s = list(input())
k = int(input())

k = s[k-1]

print("".join([k if i==k else "*" for i in s]))