n = int(input())
s = input()
k = int(input())
t = ""
for i in range(n) :
  if i != k - 1 and s[i] != s[k-1] :
    t = t + '*'
  else :
    t = t + s[i]
print(t)