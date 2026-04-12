n=int(input())
list=input().split(" ")
inst=[]
for i in list:
    inst.append(int(i))


sum=0
for i in range(n):
    if max(inst[:i+1])==inst[i]:
        sum+=1

print(sum)