# coding: utf-8
# Your code here!
N = int(input())
H = list(map(int,input().split()))
maxnum = 0
count = 0
for Hi in H:
    if Hi >= maxnum:
        count += 1
        maxnum = Hi

print(count)