str = input().split()
str2 = input().split()

a = int(str[0])

i = 1
b = int(str2[0])

for j in range(a-1):
    if b <= int(str2[j+1]):
        i = i + 1
        b = int(str2[j+1])
 
print(i)