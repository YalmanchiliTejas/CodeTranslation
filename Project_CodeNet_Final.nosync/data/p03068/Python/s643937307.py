n = int(input()) 
s = input()
m = int(input())

y = s[m-1]

for ss in s:
    print(ss if ss == y else '*',end='')