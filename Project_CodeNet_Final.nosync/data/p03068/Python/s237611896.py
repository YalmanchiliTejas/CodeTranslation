n = int(input())
s = input()
k = int(input())

s_i = s[k-1]

s_ans = ''
for i in s:
  if i == s_i:
    s_ans += i
  else:
    s_ans += '*'

print(s_ans)