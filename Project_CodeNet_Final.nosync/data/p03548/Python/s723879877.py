# coding: utf-8
# Your code here!
X,Y,Z=map(int,input().split())

X-=Z
count=0
while X>=Z+Y:
    X-=Z+Y
    count+=1

print(count)