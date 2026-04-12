a = int(input())
s = input()
k = int(input())

t = ["*"]*a
aa = s[k-1]
for f,i in enumerate(s):
  if i == aa:
    t[f] = i
print("".join(t))
