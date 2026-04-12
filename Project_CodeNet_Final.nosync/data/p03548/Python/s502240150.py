txt = input()
dic = txt.split(" ")

x=int(dic[0])
y=int(dic[1])
z=int(dic[2])
zy= y+z
k=0

while(zy*k+z<=x):
    k+=1

print(k-1)
