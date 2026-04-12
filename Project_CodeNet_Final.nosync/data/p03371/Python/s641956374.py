A,B,C,X,Y = map(int,input().split())
p_sum = []
for i in range(100001):
  p_sum.append(i*2*C + max(0,X-i)*A + max(0,Y-i)*B)
print(min(p_sum))