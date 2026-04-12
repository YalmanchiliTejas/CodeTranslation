#!/usr/bin/env/ python3
#S = input()
#N = int(input())
#A, B, C = input().split()
A, B, C, X, Y = map(int, input().split())

#N = int(input())
#H, W = map(int, input().split())
#S = [input() for _ in range(H)]
#print(A[0][0])

easy = A * X + B * Y
maxnum = max(X, Y) * 2
for i in range(maxnum, 1, -2):
    tmp = 0
    if (i == maxnum): tmp = C * i
    elif (X - (i / 2) > 0 and Y - (i / 2) > 0): tmp = A * (X - (i / 2)) + B * (Y - (i / 2)) + C * i
    elif (X - (i / 2) > 0): tmp = A * (X - (i / 2)) + C * i
    elif (Y - (i / 2) > 0): tmp = B * (Y - (i / 2)) + C * i
    if (tmp < easy): easy = tmp
print(int(easy))