modulo=10**9+7
N=int(input())
array=[(int(x))%modulo for x in input().split()]
total=((sum(array))**2)%modulo
for i in array:
    total=((total-((i%modulo)**2)))%modulo
print((total*(5*10**8+4))%modulo)