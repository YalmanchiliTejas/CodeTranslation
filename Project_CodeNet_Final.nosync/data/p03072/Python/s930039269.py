n = int(input())
l_h  = list(map(int,input().split()))
count = 1
a=[]
a.append(l_h[0])
for i in l_h[1:]:
  if i>=max(a):
    count += 1
    a.append(i)
print(count)