n = list(map(int, input().split()))
a = n[0]
b = n[1]
c = n[2]

i = 0
l = a

l -= c


while l >= (b + c):
    i += 1
    l -= (b + c)
  
print(i)