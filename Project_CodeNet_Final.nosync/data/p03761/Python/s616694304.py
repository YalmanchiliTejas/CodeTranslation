# coding: utf-8
# Your code here!
N=int(input())

ans=sorted(list(input()))

for i in range(N-1):
    temp=[]
    target=(list(input()))
    for item in ans:
        for index in range(len(target)):
            if target[index]==item:
                temp.append(target.pop(index))
                break
    ans.clear()
    ans=ans+temp

print(("").join(ans))
#for i in range(N-1):
    