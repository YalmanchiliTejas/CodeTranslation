n = int(input())
s = input()
t = [i for i in s]
k = int(input())
moji = " "
for j in range(len(t)):
  if t[j] != t[k-1]:
    t[j]="*"

for k in t:
  moji+=k
print(moji)