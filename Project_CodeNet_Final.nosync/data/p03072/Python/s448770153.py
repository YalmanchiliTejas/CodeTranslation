
#input N
#      H1,H2,,,,HN
N=int(input())
H_list=list(map(int,input().split()))

count=0

for i,H in enumerate(H_list):
    is_view=True
    j=i
    while(is_view and j>0):
        if H_list[j-1]>H:
            is_view=False
        j=j-1
    if is_view:
        count=count+1

print(count)
