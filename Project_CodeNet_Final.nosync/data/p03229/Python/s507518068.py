# coding: utf-8
# Your code here!

S = int(input())
lis = []
for item in range(0,int(S)):
    tmp = input()
    lis.append(int(tmp))
ls = sorted(lis)
lsb = sorted(lis)

center = ls[int(S/2-0.5)]
ans1 = ls[-1] - center
ls.remove(center)
for k in range(0,int(S/2)):
    try:
        
        ans1 = ans1 + ls.pop(-1) - ls[0]
        ans1 = ans1 + ls[-1] -ls.pop(0)
    except:
        break
    
if S % 2 ==0:
    print(ans1)
    exit()

center = lsb[int(S/2)]
ans2 = center - lsb[0] 

lsb.remove(center)

for k in range(0,int(S/2)):
    try:
        ans2 = ans2 + lsb[-1] - lsb.pop(0) 
        ans2 = ans2 + lsb.pop(-1) - lsb[0] 

    except:
        break
print(max(ans1,ans2))
    