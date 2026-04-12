# coding: utf-8
# Your code here!

while True:
    n=int(input())
    if n==0:
        break
    a=[int(input()) for _ in range(n)]
    print((sum(a)-max(a)-min(a))//(len(a)-2))
