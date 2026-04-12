def input_one_number():
    return int(input())
 
def input_multiple_number():
    return map(int, input().split())
 
def input_multiple_number_as_list():
    return list(map(int, input().split()))
MOD=1000000000 + 7
ans=0
a_min=0

n=input_one_number()
a=input_multiple_number_as_list()
a_sum=sum(a)
for i in range(n):
    a_min+=a[i]
    ans+=a[i]*(a_sum-a_min)
    ans=ans%MOD
print(ans)