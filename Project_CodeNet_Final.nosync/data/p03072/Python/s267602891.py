n=int(input())
l=[int(i) for i in input().split()]
maxi=0 
cnt=0 
for i in l:
    if i>=maxi:
        cnt+=1 
        maxi=i 
print(cnt)