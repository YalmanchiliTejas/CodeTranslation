N=int(input())
H_list=list(map(int,input().split()))

ans=0
h=H_list[0]

for i in range(N):
    if(h<=H_list[i]):
        h=H_list[i]
        ans+=1

print(ans)