# coding: utf-8
# Your code here!
while(1):
    risuto = []
    num = int(input())
    if num == 0 :
        break
    for i in range(num):
        risuto.append(int(input()))
    print((sum(risuto)-max(risuto)-min(risuto))//(num-2))