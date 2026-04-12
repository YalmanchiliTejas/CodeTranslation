n=int(input())
lst=list(map(int,input().split()))
aa=sum(lst) % (10**9+7)
# print(sum(lst) % (10**9+7) )
new_lst=[]
temp_1=aa
for i in range(n-1):
    temp_1-=lst[i]
    new_lst.append(temp_1)
# print(new_lst)

tem=0
for i in range(n-1):
    tem+=(lst[i] )*new_lst[i]
        # print(tem)
print(tem % (10**9 +7))
