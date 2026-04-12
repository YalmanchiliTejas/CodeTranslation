n=int(input())
m=input().split()
mt=[]
for i in m:
    mt.append(int(i))
good=1
h=mt[0]
for i in range(n-1):
    if mt[i+1]>=h:
        good+=1
        h=mt[i+1]
print(good)