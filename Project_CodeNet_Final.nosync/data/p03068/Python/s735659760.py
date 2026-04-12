#Tenka1 Programmer Beginner Contest 2019 B
n = int(input())
s = input()
k = int(input())
tr = s[k-1]
for i in s:
    print(i if i==tr else "*",end="")