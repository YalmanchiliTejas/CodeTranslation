# coding: utf-8
# Your code here!
a, b, c = map(int,input().split())

s = 100 * a + 10 * b + c

if s % 4 == 0:
    print('YES')
else:
    print('NO')