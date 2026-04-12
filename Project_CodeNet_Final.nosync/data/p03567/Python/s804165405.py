#coding:utf-8

s = input()
n = len(s)
ans = 'No'

for i in range(0, n-1):
    if s[i:i+2] == 'AC':
        ans = 'Yes'
        break

print(ans)