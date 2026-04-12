N = int(input())
Hs = list(map(int,input().split()))
num = 1
for i in range(1,len(Hs)):
    if len([j for j in Hs[:i] if Hs[i]<j])==0:
        num+=1
print(num)