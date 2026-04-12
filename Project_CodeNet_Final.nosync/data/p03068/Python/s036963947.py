num=int(input())
origin=input()
per=origin[int(input())-1]

for i in range(num):
    if origin[i] != per and origin[i] != "*":
        origin = origin.replace(origin[i], "*")
        
print(origin)