n = int(input())
h = input().split()
H = []
i = 0
while(i < n):
    H.append(int(h[i]))
    i+=1
#print(H)

i = 0
high = 0
num = 0
while(i < n):
    if(H[i] >= high):
        num += 1
    if(high < H[i]):
        high = H[i]
    i += 1

print(num)