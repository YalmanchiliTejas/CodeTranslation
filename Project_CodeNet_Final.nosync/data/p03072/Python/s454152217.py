# coding: utf-8
# Your code here!

n = int(input())

h = map(int,input().split())

m = 0
ans = 0

for i in h:
    if i >= m:
        ans+=1
        m = i

print(ans)