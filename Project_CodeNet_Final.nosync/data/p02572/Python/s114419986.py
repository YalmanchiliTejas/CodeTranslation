n=int(input())
l=input().split()
li=[int(i) for i in l]
sumi=0
for i in li:
    sumi+=i
sum2=0
for i in li:
    sum2+=(i*i)
sumi=sumi*sumi
z=(sumi-sum2)//2
print(z%1000000007)
