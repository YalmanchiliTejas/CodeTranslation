N=int(input())
H =[int(j) for j in input().split()]
min_ =H[0]
cnt=0
for i in H:
    if min_<=i:
        min_=i
        cnt+=1
        
print(cnt)