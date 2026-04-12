x,y = list(map(int, input().split()))
l = []
for i in range (x):
   l.append(list(input()))
val = 0
for j in range (x):
   val += l[j].count('#')
print('Possible' if x + y - 1 == val else 'Impossible')