n = int(input())
h = list(map(int,input().split()))
count = 1
x =[h[0]]
for i in range(1,n):
  if max(x)<=h[i]:
    count += 1
    x.append(h[i])   

print(count)
    
