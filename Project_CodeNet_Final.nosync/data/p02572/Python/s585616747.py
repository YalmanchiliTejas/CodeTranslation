mod = 10**9 + 7
N = int(input())
array = [int(i) for i in input().split()]
array_2 = [0]

for a in array:
    array_2.append(array_2[-1]+a)
    
output = 0
for i in range(len(array)-1):
    output += array[i] * (array_2[-1] - array_2[i+1])
    
print(output%mod)