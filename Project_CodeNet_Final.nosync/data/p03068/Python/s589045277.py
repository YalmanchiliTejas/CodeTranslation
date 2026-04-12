#!/usr/bin/env python3

n = int(input())
s = input()
k = int(input())

S = []
for i in s:
    S.append(i)

ta = S[k-1]
    
for i in range(n):
    if S[i] == ta:
        print(S[i],end = "")

    else:
        print("*",end = "")
        
