"""
    Author: _YL_
"""
#n, k = map(int, input().split())
lst = list(input())

n = len(lst)

i = 1
while i < n and lst[i] == lst[i-1]: i += 1

if i == n:
    print("No")
else:
    print("Yes")