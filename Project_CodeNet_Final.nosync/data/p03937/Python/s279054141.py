A,B = list(map(int, input().split()))
L = []
for i in range (A):
   L.append(list(input()))
k = 0
for j in range (A):
   k += L[j].count('#')
print('Possible' if A + B - 1 == k else 'Impossible')