N=int(input())
dataH=[int(e) for e in input().split(' ')]
c=0
for i,H in enumerate(dataH):
  c=c+1 if max(dataH[:i+1])==H else c
print(c)
