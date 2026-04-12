n,x=map(int,input().split())
len_b=2**(n+2)-3
p=[2**(i+1)-1 for i in range(n)]
start=1
end=len_b
center=(end+1)//2
count1=0
count2=n-1
while True:
    if count2==-1:
        count1+=1
        break
    elif x==start:
        break
    elif x==center:
        count1+=p[count2]+1
        break
    elif x==end:
        count1+=p[count2]*2+1
        break
    elif x<center:
        start=start+1
        end=center-1
        center=(start+end)//2
        count2-=1
    else:
        start=center+1
        end=end-1
        center=(start+end)//2
        count1+=p[count2]+1
        count2-=1
print(count1)