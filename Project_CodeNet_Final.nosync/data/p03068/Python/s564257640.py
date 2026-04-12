#coding:utf-8

n = int(input())
s = input()
k = int(input())
ans = []

for i in range(0, n):
  if s[i] != s[k-1]:
    ans.append('*')
  else:
    ans.append(s[i])

print(''.join(ans))