n=int(input())
h=[0]*n
count=int(0)
hight=int(0)
s=[int(x)  for x in input().split()]
for i in range(n):
  if s[i]>=hight:
    hight=s[i]
    count +=1
print(int(count))