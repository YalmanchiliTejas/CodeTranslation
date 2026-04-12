A,B,AB,X,Y = map(int,input().split())
p_sum = []
for i in range(10**5+1):
  p_sum.append(i*2*AB + max(0,X-i)*A + max(0,Y-i)*B)
print(min(p_sum))